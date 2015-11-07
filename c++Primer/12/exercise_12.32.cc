/*************************************************************************
	> File Name: exercise_12.32.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Wed 04 Nov 2015 09:46:22 AM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <map>
#include <set>
#include <fstream>
#include <sstream>
using namespace std;

//**************strblob***************//
class StrBlobPtr;
class TextQuery;

class StrBlob
{
public:
    friend class TextQuery;
    friend class StrBlobPtr;
    typedef vector<string>::size_type size_type;
    StrBlob();
    StrBlob(initializer_list<string>);
    
    StrBlobPtr begin();
    StrBlobPtr end();
    size_type size() const {return data_->size();}
    bool empty() const {return data_->empty();}
    void push_back(const string &str) {data_->push_back(str);}
    void pop_back();
    string& front();
    string& back();
    string& front() const;
    string& back() const;
private:
    shared_ptr<vector<string>> data_;
    void check(const string &msg) const
    {
	if(empty()) 
	    throw out_of_range(msg);
    }
};

class StrBlobPtr
{
public:
    StrBlobPtr() : curr_(0) {}
    StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr_(a.data_), curr_(sz) {}
    string& deref() const;
    StrBlobPtr& incr();
private:
    shared_ptr<vector<string>> check(size_t, const string&) const;
    weak_ptr<vector<string>> wptr_;
    size_t curr_;
};

StrBlob::StrBlob():data_(make_shared<vector<string>>()) {}
StrBlob::StrBlob(initializer_list<string> il):data_(make_shared<vector<string>>(il)) {}

StrBlobPtr StrBlob::begin() {return StrBlobPtr(*this);}
StrBlobPtr StrBlob::end() {return StrBlobPtr(*this, data_->size());}

void StrBlob::pop_back()
{
    check("pop_back on empty StrBlob");
    data_->pop_back();
}

string& StrBlob::front()
{
    check("front on empty StrBlob");
    return data_->front();
}

string& StrBlob::back()
{
    check("back on empty StrBlob");
    return data_->back();
}

string& StrBlob::front() const
{
    check("front on empty StrBlob");
    return data_->front();
}

string& StrBlob::back() const
{
    check("back on empty StrBlob");
    return data_->back();
}
/*
string& StrBlobPtr::deref() const
{
    auto sp = this->check(curr_, "dereference past end");
    return (*sp)[curr_];
}

StrBlobPtr& StrBlobPtr::incr()
{
    this->check(curr_, "increment past the end of StrBlobPtr");
    ++curr_;
    return *this;
}
*/
//*************strblob***************//

//**************************textquery***************//
class QueryResult;

class TextQuery
{
public:
    TextQuery(ifstream &);
    QueryResult Query(const string&) const;
private:
    //shared_ptr<vector<string>> file_;
    StrBlob file_;
    map<string, shared_ptr<set<size_t>>> mp_;
};

TextQuery::TextQuery(ifstream &infile)
//: file_(new vector<string>)
{
    string one_line;
    while(getline(infile, one_line))
    {
	file_.push_back(one_line);
	string word;
	size_t n = file_.size();
	istringstream iss(one_line);
	while(iss >> word)
	{
	    auto &loc = mp_[word];
	    if(!loc)
		loc.reset(new set<size_t>);
	    loc->insert(n);
	}
    }
}

class QueryResult
{
    friend ostream& print(ostream &os, QueryResult res);
public:
    QueryResult(const string s, shared_ptr<vector<string>> vec_sp, shared_ptr<set<size_t>> set_sp) :
	word_(s), file_sp_(vec_sp), line_no_(set_sp) {}
private:
    string word_;
    shared_ptr<vector<string>> file_sp_;
    shared_ptr<set<size_t>> line_no_;
};

QueryResult TextQuery::Query(const string& qs) const
{
    shared_ptr<set<size_t>> no_data(new set<size_t>);
    auto loc = mp_.find(qs);
    if(loc == mp_.end())
	return QueryResult(qs, file_.data_, no_data);
    else
	return QueryResult(qs, file_.data_, loc->second);
}

string make_plural(size_t size, const string &s1, const string &s2)
{
    return size < 2 ? string(s1) : (string(s1)+s2);
}

ostream& print(ostream& os, QueryResult res)
{
    os << "'" << res.word_ << "'" << " occurs " << res.line_no_->size() << " " <<
	make_plural(res.line_no_->size(), "time", "s") << endl;
    for(auto NO : *res.line_no_)
    {
	os << '\t' << "(line " << NO << ") :" << (*res.file_sp_)[NO-1] << endl;
    }
    return os;
}
//*****************************textquery***************//


void RunQuery(ifstream &ifs)
{
    TextQuery tq(ifs);
    string input;
    while(true)
    {
	cout << "input the word you are looking for: ";
	cin >> input;
	if(!cin || input == "q")
	{
	    cout << "Quit" << endl;
	    break;
	}
	print(cout, tq.Query(input)) << endl;
    }
}

int main()
{
    ifstream ifs("story.txt");
    RunQuery(ifs);

    return 0;
}
