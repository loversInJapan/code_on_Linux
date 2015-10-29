/*************************************************************************
	> File Name: exercise_12.2.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Tue 27 Oct 2015 10:40:23 PM PDT
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

class StrBlob
{
public:
    typedef vector<string>::size_type size_type;
    StrBlob();
    StrBlob(initializer_list<string>);
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

StrBlob::StrBlob():data_(make_shared<vector<string>>()) {}
StrBlob::StrBlob(initializer_list<string> il):data_(make_shared<vector<string>>(il)) {}

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


int main()
{
    initializer_list<string> il = {"a","an","the"};
    initializer_list<string> il2 = {"nba","cba"};
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

    return 0;
}
