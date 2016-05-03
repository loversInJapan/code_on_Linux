/*************************************************************************
	> File Name: Auto_demo.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Sat 18 Jul 2015 06:17:07 AM PDT
 ************************************************************************/

#include <iostream>
using namespace std;

int main(void)
{
    auto sz=0;
    auto pi=3.14;
    const int i = sz;

    auto &m=sz, *p=&sz;

    auto &mm=sz, *pp=&sz;

    return 0;
}
