/*************************************************************************
	> File Name: Decltype_demo.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Sat 18 Jul 2015 06:47:58 AM PDT
 ************************************************************************/

#include <iostream>
using namespace std;

int f()
{
    int x=1;
    return x;
	
}

int main(void)
{
    double x = 1.2;
    decltype(f()) sum = x;
    cout << sum << endl;

    int i=42, *p=&i, &r=i;
    decltype(*p) z=i;

    int a=0, b=0;
    decltype(a) c=a;
    ++c;
    cout << "c = " << c << endl;
    cout << "a = " << a << endl;

    decltype(a=b) d=a;
    ++d;
    cout << "d = " << d << endl;
    cout << "a = " << a << endl;

    return 0;
}
