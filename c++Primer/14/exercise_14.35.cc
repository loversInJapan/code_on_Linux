/*************************************************************************
	> File Name: exercise_14.35.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Thu 12 Nov 2015 09:42:03 AM CST
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

struct InputString{
    InputString() = default;
    const string operator()(string& s)
    {
	cin >> s;
	if(cin)
	    return s;
	else
	    return "";
    }
};

int main()
{
    string s;
    InputString is;
    is(s);
    cout << s << endl;
    return 0;
}
