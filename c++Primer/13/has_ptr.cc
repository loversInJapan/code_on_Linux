/*************************************************************************
	> File Name: has_ptr.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Sat 14 Nov 2015 06:49:24 PM CST
 ************************************************************************/

#include <iostream>
#include <memory>
#include <string>
using namespace std;

//value-like
class HasPtr{
public:
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
/*
//pointer-like
class HasPtr{
public:
    friend void swap(HasPtr&, HasPtr&);
    HasPtr(const string& s = string()) : ps_(new string(s)), i_(0), use_(new size_t(1))
    {}
    HasPtr(HasPtr& rhs)
    {
	ps_ = rhs.ps_;
	i_ = rhs.i_;
	use_ = rhs.use_;
    }
    HasPtr& operator=(HasPtr& rhs);
    ~HasPtr();
    ostream& show(ostream& os)
    {
	os << *ps_;
	return os;
    }
private:
    string* ps_;
    int i_ = 0;
    size_t* use_;
};

inline
void swap(HasPtr& lhs, HasPtr& rhs)
{
    using std::swap;
    cout << "use swap(HasPtr&, HasPtr&)" << endl;
    swap(lhs.ps_,rhs.ps_);
    swap(lhs.i_,rhs.i_);
}

HasPtr& HasPtr::operator=(HasPtr rhs)
{
    ++*rhs.use_;
    if(--*use_ == 0){
	cout << "~HasPtr" << endl;
	delete ps_;
	delete use_;
    }
    ps_ = rhs.ps_;
    i_ = rhs.i_;
    use_ = rhs.use_;
    return *this;
}

HasPtr::~HasPtr()
{
    if(--*use_ == 0){
	cout << "~HasPtr" << endl;
	delete ps_;
	delete use_;
    }

}
*/
int main()
{
    HasPtr hp("freedom");
    HasPtr ho("Paris");
    HasPtr cp(hp);
    cp.show(cout) << endl;
    cp = ho;
    cp.show(cout) << endl;
    return 0;
}
