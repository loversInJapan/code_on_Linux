/*************************************************************************
	> File Name: exercise_5.12.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Sat 08 Aug 2015 07:10:22 PM PDT
 ************************************************************************/

#include <iostream>
using namespace std;
int main(void)
{
    char ch;
    bool flag=false;
    unsigned int cnt=0;
    while(cin >> ch)
    {
	if(flag)
	{
	    if(ch=='f'||ch=='l'||ch=='i')
		++cnt;
	    flag = false;
	}else
	{
	    if(ch=='f')
		flag = true;
	}
    }
    cout << cnt << endl;

    return 0;
}
