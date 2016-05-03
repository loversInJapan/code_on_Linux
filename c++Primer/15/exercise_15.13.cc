/*************************************************************************
	> File Name: exercise_15.13.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Sat 26 Sep 2015 01:32:11 AM PDT
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;
class Base
{
public:
    Base(string name):name_(name) {}
    string name() { return name_;}
    virtual void print(ostream &os) { os << name_;}
private:
    string name_;
};

class Derived : public Base
{
public:
    Derived(string name, int val) : Base(name),ii_(val) {}
    void print(ostream &os) override 
    {
	Base::print(os);
	os <<  "  " << ii_ << endl;
    }
private:
    int ii_;
};

int main()
{
    Derived de("micheal",23);
    de.print(cout);
    return 0;
}
