/*************************************************************************
	> File Name: exercise_9.5.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Sun 20 Sep 2015 05:32:55 AM PDT
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

vector<int>::iterator &
find(vector<int>::iterator &begin, vector<int>::iterator &end, int val)
{
    for(; begin != end; ++begin)
    {
	if(*begin == val)
	    return begin;
    }
    return end;
}

int main()
{
    vector<int> vec{1,2,3,4,5};
    auto begin = vec.begin();
    auto end = vec.end();
    auto result = find(begin, end, 2);
    if(result == end)
	cout << "not found target" << endl;
    else
	cout << "found target " << *result << endl;

    return 0;
}
