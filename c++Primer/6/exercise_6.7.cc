/*************************************************************************
	> File Name: exercise_6.7.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Mon 10 Aug 2015 08:06:36 PM PDT
 ************************************************************************/

#include <iostream>
#include "Charpter6.h"
using namespace std;
int func()
{
    static unsigned int func_cnt=0;
    if(func_cnt==0)
    {
	++func_cnt;
	return 0;
    }else
    {
	return 1;
    }
}

