/*************************************************************************
	> File Name: NumberOfVowel.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Sat 08 Aug 2015 06:50:54 PM PDT
 ************************************************************************/

#include <iostream>
using namespace std;
int main(void)
{
    char ch;
    int vowel_cnt=0;
    while(cin >> ch)
    {
	if(ch == 'a' || ch == 'e'||ch=='i'||ch=='o'||ch=='u')
	    ++vowel_cnt;
    }
    cout << vowel_cnt << endl;

    return 0;
}
