/*************************************************************************
	> File Name: exercise_13.31.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Sat 14 Nov 2015 10:16:31 PM CST
 ************************************************************************/

#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//value-like
class HasPtr{
public:
    friend bool operator<(HasPtr, HasPtr);
    //friend [](HasPtr, HasPtr);
    friend void swap(HasPtr&, HasPtr&);
    HasPtr(const string &s = string()) : ps_(new string(s)),i_(0){}
    HasPtr(const HasPtr& rhs)
    {
	ps_ = new string(*rhs.ps_);
	i_ = rhs.i_;
    }
    HasPtr& operator=(HasPtr rhs);
    ~HasPtr()
    {
	delete ps_;
    }
    ostream& show(ostream& os)
    {
	os << *ps_;
	return os;
    }
private:
    string* ps_;
    int i_ = 0;
};

bool operator<(HasPtr lhs, HasPtr rhs)
{
    return *lhs.ps_ < *rhs.ps_ ? true : false;
}

inline
void swap(HasPtr& lhs, HasPtr& rhs)
{
    using std::swap;
    cout << "use swap(HasPtr&, HasPtr&)" << endl;
    swap(lhs.ps_,rhs.ps_);
    swap(lhs.i_,rhs.i_);
}

HasPtr&
HasPtr::operator=(HasPtr rhs)
{
    /*
    string* newp = new string(*rhs.ps_);
    delete ps_;
    ps_ = newp;
    i_ = rhs.i_;
    */
    swap(*this, rhs);
    return *this;
}

int main()
{
    HasPtr hp("freedom");
    HasPtr ho("Paris");
    HasPtr cp(hp);
    cp.show(cout) << endl;
    cp = ho;
    cp.show(cout) << endl;
    HasPtr v1("hello");
    HasPtr v2("apple");
    vector<HasPtr> vec = {hp, ho, v1, v2};
    sort(vec.begin(), vec.end(), operator<(HasPtr lrs, HasPtr rhs));
	    //[](HasPtr a, HasPtr b){return *a.ps_ < *b.ps_ ? true : false;});
    for(auto elem : vec){
	elem.show(cout) << endl;
    }
    return 0;
}
