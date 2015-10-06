/*************************************************************************
	> File Name: exercise_9.27.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Tue 06 Oct 2015 02:20:59 AM PDT
 ************************************************************************/

#include <iostream>
#include <forward_list>
using namespace std;

void DeleteOdd(forward_list<int> &flist)
{
    auto pre = flist.before_begin();
    auto cur = flist.begin();
    while(cur != flist.end())
    {
	if(*cur % 2)
	{
	    cur = flist.erase_after(pre);
	}
	else
	{
	    ++pre;
	    ++cur;
	}
    }
}

int main()
{
    forward_list<int> fl{1,2,3,4,5,6,7,8,9,11,12,15,16,76,100};
    DeleteOdd(fl);
    for(auto i : fl)
	cout << i << " ";
    cout << endl;

    return 0;
}
