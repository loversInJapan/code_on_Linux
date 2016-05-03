/*************************************************************************
	> File Name: exercise_6.42.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Sun 30 Aug 2015 08:52:14 PM PDT
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;
string MakePlural(size_t ctr, const string &beg, const string &end="s")
{
    return (ctr>1) ? beg+end : beg;
}
int main(void)
{
    string output_str = MakePlural(1,"apple");
    cout << output_str << endl;

    return 0;
}
