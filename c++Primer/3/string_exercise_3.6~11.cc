/*************************************************************************
	> File Name: string_exercise_3.6~11.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Mon 20 Jul 2015 08:04:59 PM PDT
 ************************************************************************/

#include <iostream>
using namespace std;
int main(void)
{
    string s = "abcdefg";
    for(char &rfe : s)
	rfe = 'X';
    cout << s << endl;

    string s1 = "haha";
    cout << s1[0] << endl;

    const string s2 = "asdf";
    for(auto &ch : s2)
	;//ch = 'Z';

    return 0;
}
