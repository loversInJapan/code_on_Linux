/*************************************************************************
	> File Name: a++and++a.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Fri 16 Oct 2015 03:49:45 AM PDT
 ************************************************************************/

#include <iostream>
using namespace std;
int main(void)
{
    int a = 3, b = 2;
    //a=a++*a++;
    int sum = a+++(++b);
    cout << a << endl;
    cout << sum << endl;

    return 0;
}
