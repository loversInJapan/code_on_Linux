/*************************************************************************
	> File Name: cin.cc
	> Author: Yikang Chen
	> Mail: sysucyk2010@163.com
	> Created Time: 2015年12月11日 星期五 16时22分31秒
 ************************************************************************/

#include <iostream>
using namespace std;

int main()
{
    char ch;
    cin >> noskipws;
    while(cin >> ch)
        cout << ch;
    cin >> skipws;
    return 0;
}
