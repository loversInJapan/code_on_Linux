/*************************************************************************
	> File Name: exercise_8.1.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Tue 15 Sep 2015 02:04:54 AM PDT
 ************************************************************************/

#include <iostream>
using namespace std;

istream &print(istream &is)
{
    string s;
    while(is >> s)
        cout << s << endl;
    is.clear();

    return is;
}

int main()
{
    print(cin);
    return 0;
}
