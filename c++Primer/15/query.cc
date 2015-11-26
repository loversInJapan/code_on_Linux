/*************************************************************************
	> File Name: query.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Sun 22 Nov 2015 09:57:35 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <set>
#include <memory>
#include <iterator>
#include <utility>
#include <algorithm>
#include <cctype>
using namespace std;

//class TextQuery and class QueryResult
class QueryResult;

class TextQuery{
public:
    TextQuery(ifstream&);
    QueryResult query(const string&) const;
private:
    shared_ptr<vector<string>> file_;
    map<string, shared_ptr<set<size_t>>> wm_;
};

void clean(string& s)
{
    char& c = s[0];
    if(ispunct(c))
	s.erase(0,1);
    char& ch = s[s.size()-1];
    if(ispunct(ch))
	s.erase(s.size()-1,1);
    return;
}

TextQuery::TextQuery(ifstream& ifs) : file_(new vector<string>)
{
    string text;
    size_t lineNo = 1;
    while(getline(ifs, text)){
	file_->push_back(text);
	istringstream iss(text);
	string word;
	while(iss >> word){
	    clean(word);
	    auto& sp = wm_[word];
	    if(!sp){
	        sp.reset(new set<size_t>);
	    }
	    sp->insert(lineNo);
	}
	++lineNo;
    }
}

class QueryResult{
friend ostream& print(ostream&, const QueryResult&);
public:
    QueryResult(const string& s, shared_ptr<set<size_t>> sp, shared_ptr<vector<string>> file):
    seek_(s),lines_(sp),texts_(file){}
    set<size_t>::iterator begin();
    set<size_t>::iterator end();
    shared_ptr<vector<string>> get_file();
private:
    string seek_;
    shared_ptr<set<size_t>> lines_;
    shared_ptr<vector<string>> texts_;
};

ostream&
print(ostream& os, const QueryResult& qr)
{
    os << qr.seek_ << " occurs " << qr.lines_->size() << " "
	<< (qr.lines_->size() > 2 ? " times" : " time") << endl;
    for(auto num : *qr.lines_)
        os << "\t(line " << num << ")" << (*qr.texts_)[num-1] << endl;
    return os;
}

inline
set<size_t>::iterator QueryResult::begin() 
{
    return lines_->begin();
}

inline
set<size_t>::iterator QueryResult::end() 
{
    return lines_->end();
}

inline
shared_ptr<vector<string>> QueryResult::get_file() 
{
    return texts_;
}

QueryResult TextQuery::query(const string& s) const
{
    auto loc = wm_.find(s);
    static shared_ptr<set<size_t>> nodata(new set<size_t>);
    if(loc == wm_.end())
	return QueryResult(s, nodata, file_);
    else
	return QueryResult(s, loc->second, file_);
}

//class QueryBase
class QueryBase{
    friend class Query;
protected:
    virtual ~QueryBase() = default;
private:
    virtual QueryResult eval(const TextQuery&) const = 0;
    virtual string rep() const = 0;
};

//class Query
class Query{
    friend Query operator~(const Query&);
    friend Query operator&(const Query&, const Query&);
    friend Query operator|(const Query&, const Query&);
public:
    Query(const string&);
    //Query(const Query& rhs) : q_(rhs.q_) {}
    QueryResult eval(const TextQuery& t) const
    { 
	return q_->eval(t);
    }
    string rep() const
    {
	return q_->rep();
    }
private:
    shared_ptr<QueryBase> q_;
    Query(shared_ptr<QueryBase> query) : q_(query){}
};

ostream&
operator<<(ostream &os, Query& q)
{
    return os << q.rep();
}

//class WordQuery
class WordQuery:public QueryBase{
    friend class Query;
    WordQuery(const string& s) : word_(s){}
    QueryResult eval(const TextQuery& t) const
    {
	return t.query(word_);
    }
    string rep() const 
    {
	return word_;
    }
    string word_;
};

inline
Query::Query(const string& s) : q_(new WordQuery(s))
{}

//class NotQuery
class NotQuery : public QueryBase{
    friend Query operator~(const Query&);
    NotQuery(const Query& q) : query_(q) {}
    string rep() const
    {
	return "~(" + query_.rep() + ")";
    }
    QueryResult eval(const TextQuery& t) const;
    Query query_;
};

inline
Query operator~(const Query& operand)
{
    return shared_ptr<QueryBase>(new NotQuery(operand));
}

//class BinaryQuery
class BinaryQuery : public QueryBase{
protected:
    BinaryQuery(const Query &lhs, const Query &rhs, string s) :
	left_(lhs), right_(rhs), ops_(s) {}
    string rep() const 
    {
	return "(" + left_.rep() + " " + ops_
	    + " " + right_.rep() + ")";
    }
    Query left_, right_;
    string ops_;
};

//class AndQuery
class AndQuery : public BinaryQuery{
    friend Query operator&(const Query& left, const Query& right);
    AndQuery(const Query& left, const Query& right) : BinaryQuery(left, right, "&")
    {}
    QueryResult eval(const TextQuery&) const;
};

inline
Query operator&(const Query& left, const Query& right)
{
    return shared_ptr<QueryBase>(new AndQuery(left, right));
}

//class OrQuery
class OrQuery : public BinaryQuery{
    friend Query operator|(const Query&, const Query&);
    OrQuery(const Query& lhs, const Query& rhs) : BinaryQuery(lhs, rhs, "|")
    {}
    QueryResult eval(const TextQuery& ) const;
};

inline
Query operator|(const Query& lhs, const Query& rhs)
{
    return shared_ptr<QueryBase>(new OrQuery(lhs, rhs));
}

//eval()
QueryResult
OrQuery::eval(const TextQuery& text) const
{
    auto right = right_.eval(text), left = left_.eval(text);
    auto ret_lines = make_shared<set<size_t>>(left.begin(), left.end());
    ret_lines->insert(right.begin(), right.end());
    return QueryResult(rep(), ret_lines, left.get_file());
}

QueryResult
AndQuery::eval(const TextQuery& text) const
{
    auto left = left_.eval(text), right = right_.eval(text);
    auto ret_lines = make_shared<set<size_t>>();
    set_intersection(left.begin(),left.end(),right.begin(),right.end(),
	    inserter(*ret_lines, ret_lines->begin()));
    return QueryResult(rep(),ret_lines,left.get_file());
}

QueryResult
NotQuery::eval(const TextQuery& text) const
{
    auto result = query_.eval(text);
    auto ret_lines = make_shared<set<size_t>>();
    auto beg = result.begin(), end = result.end();
    auto sz = result.get_file()->size();
    for(size_t n = 1; n <= sz; ++n){
	if(beg == end || *beg != n)
	    ret_lines->insert(n);
	else if(beg != end)
	    ++beg;
    }
    return QueryResult(rep(), ret_lines, result.get_file());
}
//main
TextQuery get_file(int argc, char** argv)
{
    ifstream infile;
    if(argc == 2)
	infile.open(argv[1]);
    if(!infile)
	throw runtime_error("No input file!");

    return TextQuery(infile);
}

bool get_word(string& s)
{
    cout << "enter a word to search for, or 'q' to quit: ";
    cin >> s;
    if(!cin || s == "q")
	return false;
   else
       return true;
}

bool get_word(string& s1, string& s2)
{
    cout << "enter two words to search for, or 'q' to quit:  ";
    cin >> s1;
    if(!cin || s1 == "q")
	return false;
    cin >> s2;
    return true;
}

int main(int argc, char** argv)
{
    TextQuery file = get_file(argc, argv);

    do{
	string s;
	if(!get_word(s))
	    break;
	Query q = ~Query(s);
	auto result = q.eval(file);
	print(cout, result);
/*	string s1, s2, s3;
	if(!get_word(s1, s2))
	    break;
	cout << "enter the third word: ";
	cin >> s3;
	Query query = Query(s1) & Query(s2) | Query(s3);
	auto result = query.eval(file);
	print(cout, result);

	result = Query(s1).eval(file);
	print(cout, result);

	result = Query(s2).eval(file);
	print(cout, result);
*/
    }while(true);
    return 0;
}




