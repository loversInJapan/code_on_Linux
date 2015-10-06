/*************************************************************************
	> File Name: add_without_+.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Mon 05 Oct 2015 11:42:00 PM PDT
 ************************************************************************/

#include <iostream>
using namespace std;
int Add(int num1, int num2)
{
    int sum, carry;
    do
    {
	sum = num1 ^ num2;
	carry = (num1 & num2) << 1;
	num1 = sum;
	num2 = carry;
    }while(num2);
    return num1;
}

int main()
{
    int sum = Add(1,3);
    cout << sum << endl;
    return 0;
}
