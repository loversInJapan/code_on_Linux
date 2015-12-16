/*************************************************************************
	> File Name: exercise_18.17.cc
	> Author: Yikang Chen
	> Mail: sysucyk2010@163.com
	> Created Time: 2015年12月16日 星期三 21时41分26秒
 ************************************************************************/

#include <iostream>

namespace Exercise{
    int ivar = 0;
    double dvar = 0;
    const int limit = 1000;
}

int ivar = 0;
/*
using Exercise::ivar;
using Exercise::dvar;
using Exercise::limit;
*/
//using namespace Exercise;
void manip()
{
    /*
    using Exercise::ivar;
    using Exercise::dvar;
    using Exercise::limit;
    */
    using namespace Exercise;
    double dvar = 3.14;
    int iobj = limit + 1;
    ++Exercise::ivar;
    ++::ivar;
}

int main()
{
    return 0;
}
