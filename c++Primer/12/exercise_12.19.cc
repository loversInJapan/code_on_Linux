/*************************************************************************
	> File Name: exercise_12.19.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Fri 30 Oct 2015 03:25:28 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

class StrBlobPtr;

class StrBlob
{
public:
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

shared_ptr<vector<string>> 
StrBlobPtr::check(size_t i, const string &msg) const
{
    auto ret = wptr_.lock();
    if(!ret)
	throw runtime_error("unbound StrBlobPtr");
    if(i >= ret->size())
	throw out_of_range(msg);
    return ret;
}

string& StrBlobPtr::deref() const
{
    auto sp = check(curr_, "dereference past end");
    return (*sp)[curr_];
}

StrBlobPtr& StrBlobPtr::incr()
{
    check(curr_, "increment past the end of StrBlobPtr");
    ++curr_;
    return *this;
}


int main()
{
    initializer_list<string> il = {"a","an","the"};
    initializer_list<string> il2 = {"nba","cba"};
    StrBlob sb1(il);
    StrBlobPtr sp1(sb1);
    sp1.incr();
    sp1.incr();
    sp1.incr();
    StrBlobPtr sp2(sb1, sb1.size());
    sp2.incr();
    cout << sp2.deref() << endl;
    /*
    StrBlob sb1(il2);
    {
	StrBlob sb2(il);
        cout << sb1.front() << endl;
	sb1 = sb2;
        cout << sb1.front() << endl;
	sb2.push_back("about");
	sb1.push_back("new");
        //cout << "sb1.size() = " << sb1.size() << endl;
        cout << "sb2.size() = " << sb2.size() << endl;
    }
    cout << "sb1.size() = " << sb1.size() << endl;
    cout << sb1.front() << endl;

    const StrBlob sb3(il);
    cout << sb3.front() << endl;
    cout << sb3.back() << endl;
    //sb1.pop_back();
    //sb1.front();
    //cout << sb1.back() << endl;
    */

    return 0;
}
