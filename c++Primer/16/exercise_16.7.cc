/*************************************************************************
	> File Name: exercise_16.7.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Thu 26 Nov 2015 10:01:51 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <unsigned N>
constexpr unsigned get_size(const int (&array)[N])
{
    return sizeof(array)/sizeof(int);
}

template <typename T>
constexpr unsigned get_size(const T& v)
{
    return v.size();
}

int main()
{
    int arr[10] = {1,2,3,4,5,6};
    auto sz = get_size(arr);
    cout << sz << endl;
    vector<string> vec = {"asd ","asqwq","agf"};
    sz = get_size(vec);
    cout << sz << endl;
    return 0;
}
