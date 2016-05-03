/*************************************************************************
	> File Name: find_char.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Tue 11 Aug 2015 01:32:24 AM PDT
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;
string::size_type find_char(const string &str, char ch, 
				string::size_type &cnt)
{
    auto ret = str.size();
    for(decltype(ret) i=0; i!=str.size(); ++i)
    {
	if(str[i] == ch)
	{
	    if(ret == str.size())
		ret=i;
	    ++cnt;
	}
    }
    return ret;
}
int main(void)
{
    string str;
    cin >> str;
    string::size_type cnt=0;
    auto found = find_char(str,'c', cnt);
    cout << "the first position of 'c' is " << found << " and occurs " 
	 << cnt << " times" << endl;
    return 0;
}
