/*************************************************************************
	> File Name: exercise_9.4.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Sun 20 Sep 2015 05:20:03 AM PDT
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

bool find(vector<int>::iterator begin, vector<int>::iterator end, int val)
{
    auto b = begin;
    auto e = end;
    for(; b != e; ++b)
    {
	if(*b == val)
	    return true;
    }
    return false;
}

int main()
{
    vector<int> vec{1,2,3,4,5};
    auto begin = vec.begin();
    auto end = vec.end();
    auto result = find(begin, end, 6);
    if(result)
	cout << "found target" << endl;
    else
	cout << "not found" << endl;

    return 0;
}
