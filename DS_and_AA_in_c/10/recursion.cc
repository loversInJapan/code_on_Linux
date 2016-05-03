/*************************************************************************
	> File Name: recursion.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Sat 12 Sep 2015 07:06:55 PM PDT
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

double eval(int n)
{
    if(n == 0)
    {
	return 1;
    }
    double sum=0.0;
    for(int i = 0; i < n; ++i)
    {
	sum+=eval(i);
    }
    return 2*sum/n + n;
}

double eval_norecursion(int n)
{
    vector<double> answer(n+1);
    vector<double> sum(n+1);

    answer[0] = 1.0;
    sum[0] = 1.0;
    for(int i = 1; i <= n; ++i)
    {
	answer[i] = 2*sum[i-1] / i + i;
	sum[i] = sum[i-1] + answer[i];
    }

    return answer[n];
}

int main()
{
    cout << eval(10) << endl;
    cout << eval_norecursion(10) << endl;

    return 0;
}
