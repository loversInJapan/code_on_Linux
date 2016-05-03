/*************************************************************************
	> File Name: test.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Sun 12 Jul 2015 06:44:44 AM PDT
 ************************************************************************/

#include <iostream>
using namespace std;

class A
{
public:
	void print()
	{
		cout << "hello world" << endl;
	}
};

class B:public A
{
	void Print()
	{
		cout << "HAHA" << endl;
	}
};

int main(void)
{
	B b;
	b.print();

	return 0;
}
