/*************************************************************************
	> File Name: char_unsigned.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Tue 15 Sep 2015 07:52:58 PM PDT
 ************************************************************************/

#include <iostream>
using namespace std;
int main()
{
    char b[] = "12345678";
    unsigned short *c = (unsigned short*) (b+3);
    cout << *c << endl;

    return 0;
}
