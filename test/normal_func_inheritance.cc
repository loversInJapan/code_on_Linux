/*************************************************************************
	> File Name: normal_func_inheritance.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Sun 18 Oct 2015 09:03:50 PM PDT
 ************************************************************************/

#include <iostream>
using namespace std;
class A
{
public:
    virtual void foo()
    {
	printf("foo() in class A\n");
    }
    virtual ~A(){}
};

class B : public A
{
public:
    void foo()
    {
	cout << "foo() in class B" << endl;
    }
};

int main()
{
    A a;
    B b;
    A *pa = &a;
    A *pb = &b;
    pa->foo();
    pb->foo();
    //delete pa;
    //delete pb;

    return 0;
}
