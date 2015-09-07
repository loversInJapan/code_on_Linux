/*************************************************************************
	> File Name: exercise_6.54~56.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Mon 31 Aug 2015 07:31:33 AM PDT
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;
int Sum(int,int);
int Subtract(int,int);
int Multiply(int,int);
int Divide(int,int);
int main()
{
    vector<int(*)(int,int)> func_vec;
    int (*pf_sum)(int,int) = Sum;
    int (*pf_sub)(int,int) = Subtract;
    int (*pf_mul)(int,int) = Multiply;
    int (*pf_div)(int,int) = Divide;
    func_vec.push_back(pf_div);
    func_vec.push_back(pf_sum);
    func_vec.push_back(pf_sub);
    func_vec.push_back(pf_mul);

    for(auto call_func : func_vec)
	cout << call_func(4,2) << endl;

    return 0;
}
int Sum(int num_1, int num_2)
{
    return num_1+num_2;
}
int Subtract(int num_1, int num_2)
{
    return num_1 - num_2;
}
int Multiply(int num_1, int num_2)
{
    return num_1 * num_2;
}
int Divide(int num_1, int num_2)
{
    return num_1 / num_2;
}
