/*************************************************************************
	> File Name: exercise_6.51.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Mon 31 Aug 2015 02:27:14 AM PDT
 ************************************************************************/

#include <iostream>
using namespace std;
void f();
void f(int);
void f(int,int);
void f(double,double = 3.14);
int main()
{
    f(2.56);
    f(42);
    f(42,0);
    f(2.56,3.14);
    return 0;
}
void f()
{
    cout << "f()" << endl;
}
void f(int val)
{
    cout << "f(int)" << endl;
}
void f(int val_1, int val_2)
{
    cout << "f(int,int)" << endl;
}
void f(double val_1, double val_2)
{
    cout << "f(double,double=3.14)" << endl;
}
