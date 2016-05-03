/*************************************************************************
	> File Name: exercise_9.14.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Tue 22 Sep 2015 01:22:56 AM PDT
 ************************************************************************/

#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main()
{
    list<char *> li;
    char *a = "abc";
    char *b = "bca";
    char *c = "eee";
    li.push_back(a);
    li.push_back(b);
    li.push_back(c);
    vector<string> vec;
    vec.assign(li.begin(),li.end());
    for(auto out : vec)
	cout << out << endl;

    return 0;

}
