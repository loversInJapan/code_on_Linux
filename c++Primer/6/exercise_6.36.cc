/*************************************************************************
	> File Name: exercise_6.36.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Sun 16 Aug 2015 08:22:37 AM PDT
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;
string (&func1(int i))[10];
auto func2(int i)->int(&)[10];
int odd[] = {1,3,5,7,9};
int even[] = {0,2,4,6,8};
decltype(odd) *arr_ptr(int i)
{
    return (i%2) ? &odd : &even;
}
int main()
{
    auto *result_ptr = arr_ptr(2);
    for(int i=0; i < 5; ++i)
	cout << (*result_ptr)[i] << " ";
    cout << endl;
    return 0;
}
