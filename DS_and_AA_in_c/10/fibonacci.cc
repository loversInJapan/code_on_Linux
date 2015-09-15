/*************************************************************************
	> File Name: fibonacci.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Sat 12 Sep 2015 06:34:18 PM PDT
 ************************************************************************/

#include <iostream>
using namespace std;
class Fibonacci
{
public:
    int fib(int);
    int fibonacci(int);
};

int Fibonacci::fib(int n)
{
    if(n <= 1)
	return 1;
    else
	return fib(n-1) + fib(n-2);
}

int Fibonacci::fibonacci(int n)
{
    int last = 1;
    int next_to_last = 1;
    int answer = 1;
    if(n <= 1)
	return 1;
    else
    {
	for(int i = 2; i <= n; ++i)
	{
	    answer = last + next_to_last;
	    next_to_last = last;
	    last = answer;
	}
   	return answer; 
    }
}

int main()
{
    Fibonacci fibs;
    cout << fibs.fib(40) << endl;
    cout << fibs.fibonacci(40) << endl;

    return 0;
}
