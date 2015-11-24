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
#include <utility>
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

TextQuery::TextQuery(ifstream& ifs) : file_(new vector<string>)
{
    string text;
    size_t lineNo = 1;
    while(getline(ifs, text)){
	file_->push_back(text);
	istringstream iss(text);
	string word;
	while(iss >> word){
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
private:
    string seek_;
    shared_ptr<set<size_t>> lines_;
    shared_ptr<vector<string>> texts_;
};

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
    Query(const Query& rhs) : q_(rhs.q_) {}
    QueryResult eval(const TextQuery& t) const
    { return q_->eval(t);}
    string rep() const
    { return q_->rep();}
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
    {return t.query(word_);}
    string rep() const 
    {return word_;}
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
    {return "~(" + query_.rep() + ")";}
    QueryResult eval(const TextQuery& t) const;
    Query query_;
};

inline
Query operator~(const Query& operand)
{
    return shared_ptr<QueryBase>(new NotQuery(operand));
}

int main()
{
    return 0;
}
