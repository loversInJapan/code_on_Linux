/*************************************************************************
	> File Name: iomanip.cc
	> Author: Yikang Chen
	> Mail: sysucyk2010@163.com
	> Created Time: 2015年12月11日 星期五 16时08分20秒
 ************************************************************************/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    cout << "Precision: " << cout.precision() <<
        ", Val: " << sqrt(2.0) << endl;
    cout.precision(12);
    cout << "Precision: " << cout.precision() <<
        ", Val: " << sqrt(2.0) << endl;
    cout << setprecision(3);
    cout << "Precision: " << cout.precision() <<
        ", Val: " << sqrt(2.0) << endl;
    cout << setprecision(6);
    cout << sqrt(3.0) << endl;
    return 0;
}
