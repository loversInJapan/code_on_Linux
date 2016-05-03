/*************************************************************************
	> File Name: exercise_9.28.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Tue 06 Oct 2015 02:39:15 AM PDT
 ************************************************************************/

#include <iostream>
#include <forward_list>
using namespace std;

void CompareAndInsert(forward_list<string> &flist, const string &cmp, const string &insert)
{
    auto cur = flist.begin();
    auto pre = flist.before_begin();
    while(cur != flist.end())
    {
	if(*cur == cmp)
	{
	    flist.insert_after(cur, insert);
	    return ;
	}
	++pre;
	++cur;
    }
    ;
    flist.insert_after(pre,insert);
    return ;
}

int main()
{
    forward_list<string> fl = {"nike","adidas","puna","anta","lining"};
    CompareAndInsert(fl,"adidas","converse");
    CompareAndInsert(fl,"acis","new balance");
    for(auto i : fl)
    {
	cout << i << " ";
    }
    cout << endl;

    return 0;
}
