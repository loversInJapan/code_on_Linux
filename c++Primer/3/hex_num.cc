/*************************************************************************
	> File Name: hex_num.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Mon 20 Jul 2015 07:35:12 PM PDT
 ************************************************************************/

#include <iostream>
using namespace std;
int main(void)
{
    const string hex_digit = "0123456789ABCDEF";
    string::size_type n;
    string result;
    while(cin >> n)
	if(n < hex_digit.size())
	    result+=hex_digit[n];
    cout << result << endl;

    return 0;
}
