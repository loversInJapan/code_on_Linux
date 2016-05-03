/*************************************************************************
	> File Name: exercise_11.8.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Tue 13 Oct 2015 08:10:50 PM PDT
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    vector<string> vec_str;
    string word;
    while(cin >> word)
    {
	int flag = 0;
	for(auto &str : vec_str)
	{
	    if(str == word)
	    {
		++flag;
		break;
	    }
	}
	if(!flag)
	    vec_str.push_back(word);
    }
    for(auto &out : vec_str)
	cout << out << endl;

    return 0;
}
