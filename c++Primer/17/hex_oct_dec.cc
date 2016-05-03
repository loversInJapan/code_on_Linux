/*************************************************************************
	> File Name: hex_oct_dec.cc
	> Author: Yikang Chen
	> Mail: sysucyk2010@163.com
	> Created Time: 2015年12月11日 星期五 15时57分01秒
 ************************************************************************/

#include <iostream>
using namespace std;

int main()
{
    cout << showbase << uppercase;
    cout << "default: " << 15 << " " << 1024 << endl;
    cout << "octal: " << oct << 15 << " " << 1024 << endl;
    cout << "hex: " << hex << 15 << " " << 1024 << endl;
    cout << "decimal: " << dec << 15 << " " << 1024 << endl;
    cout << noshowbase << nouppercase;
    return 0;
}
