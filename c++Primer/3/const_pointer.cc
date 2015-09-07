/*************************************************************************
	> File Name: const_pointer.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Tue 21 Jul 2015 08:59:13 AM PDT
 ************************************************************************/

#include <iostream>
using namespace std;
int main(void)
{
    int i=3;
    int *const p = &i;
    *p = 5;
    const int *cp = &i;
    *cp = 12;

    return 0;
}
