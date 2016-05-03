/*************************************************************************
	> File Name: func_main.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Mon 10 Aug 2015 08:32:54 PM PDT
 ************************************************************************/

#include <iostream>
#include "Charpter6.h"
using namespace std;
int main(void)
{
    cout << "first call of function func(), the return value is " << func()
	 << endl;
    cout << "after first call, the return value is " << func() << endl;
    cout << "after first call, the return value is " << func() << endl;
    cout << "after first call, the return value is " << func() << endl;
    cout << "after first call, the return value is " << func() << endl;

    return 0;
}
