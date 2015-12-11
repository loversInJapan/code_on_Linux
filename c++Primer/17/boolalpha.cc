/*************************************************************************
	> File Name: boolalpha.cc
	> Author: Yikang Chen
	> Mail: sysucyk2010@163.com
	> Created Time: 2015年12月11日 星期五 15时51分39秒
 ************************************************************************/

#include <iostream>
using namespace std;

int main()
{
    cout << true << " " << false << endl;
    cout << boolalpha << true << " " << false << endl;
    cout << true << " " << false << endl;
    cout << noboolalpha;
    cout << true << " " << false << endl;
    return 0;
}
