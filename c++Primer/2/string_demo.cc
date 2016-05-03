/*************************************************************************
	> File Name: string_demo.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Sat 18 Jul 2015 07:52:55 AM PDT
 ************************************************************************/

#include <iostream>
using namespace std;

int main(void)
{
	cout << "this is a long string"
	  "that needs two lines" << endl;
	string a(5,'f');
	cout << a << endl;

	return 0;
}
