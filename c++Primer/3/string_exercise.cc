/*************************************************************************
	> File Name: string_exercise.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Mon 20 Jul 2015 08:11:28 AM PDT
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;
int main(void)
{
    string s1, s2;
    cin >> s1 >> s2;
    //cout << s1>s2?s1:s2 << endl;
    /*if(s1 > s2)
	cout << s1 << endl;
    else
	cout << s2 << endl;
    */
    if(s1.size()==s2.size())
	;
    else
    {
	if(s1.size()>s2.size())
	    cout << s1 << endl;
	else
	    cout << s2 << endl;
    }

    return 0;
}
