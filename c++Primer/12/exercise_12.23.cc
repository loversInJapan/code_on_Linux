/*************************************************************************
	> File Name: exercise_12.23.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Sat 31 Oct 2015 05:09:04 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int main()
{
    char *ptr = new char[5];
    cin.getline(ptr, 30, '\n');
    cout << ptr << endl;
    delete []ptr;

    return 0;
}
