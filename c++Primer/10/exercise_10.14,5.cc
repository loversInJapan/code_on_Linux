/*************************************************************************
	> File Name: exercise_10.14,5.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Fri 23 Oct 2015 01:01:08 AM PDT
 ************************************************************************/

#include <iostream>
using namespace std;

int main()
{
    int i = 2, j = 3;
    auto lambda = [&i,&j](int a, int b)mutable -> int {++i; ++j; return a+b+i+j;};
    cout << lambda(1,4) << endl;
    cout << "i = " << i << ", j = " << j << endl;
    return 0;
}
