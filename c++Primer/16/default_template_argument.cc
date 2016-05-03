/*************************************************************************
	> File Name: default_template_argument.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Wed 02 Dec 2015 09:49:26 AM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

template <typename T, typename F = less<T>>
int compare(const T& v1, const T& v2, F f = F())
{
    if(f(v1,v2)) return 1;
    if(f(v2,v1)) return -1;
    return 0;
}

int main()
{
    int v1, v2;
    cin >> v1 >> v2;
    cout << compare(v1,v2) << endl;
    return 0;
}
