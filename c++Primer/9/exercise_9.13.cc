/*************************************************************************
	> File Name: exercise_9.13.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Sun 20 Sep 2015 06:56:15 AM PDT
 ************************************************************************/

#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main()
{
    list<int> l = {1,2,3,4,5};
    vector<double> v(l.begin(), l.end());
    for(auto out : v)
	cout << out << endl;
    vector<int> vi = {11,22,33};
    vector<double> vd(vi.begin(), vi.end());
    for(auto out : vd)
	cout << out << endl;

    return 0;
}
