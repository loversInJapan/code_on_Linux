/*************************************************************************
	> File Name: exercise_5.14.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Sat 08 Aug 2015 07:36:09 PM PDT
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(void)
{
    string input_str;
    unsigned int max_cnt=0;
    string max_cnt_str;
    unsigned int temp_cnt=0;
    string temp_cnt_str;
    while(cin >> input_str)
    {
	if(temp_cnt==0)
	{
	    temp_cnt_str=input_str;
	    ++temp_cnt;
	}
	else
	{
	    if(temp_cnt_str == input_str)
		++temp_cnt;
	    else
	    {
		if(temp_cnt > max_cnt)
		{
		    max_cnt =  temp_cnt;
		    max_cnt_str = temp_cnt_str;
		}
		temp_cnt_str = input_str;
		temp_cnt = 1;
	    }
	}
    }
    if(max_cnt > 1)
    {
	cout << "\"" << max_cnt_str << "\"" << " shows " << max_cnt << " times!" << endl;
    }
    else
    {
	cout << "no word shows continuously!" << endl;
    }

    return 0;
}


