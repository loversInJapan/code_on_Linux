/*************************************************************************
	> File Name: exercise_6.44.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Mon 31 Aug 2015 12:58:25 AM PDT
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;
inline bool IsShorter(string &, string &);
int main()
{
    string s1{"apple"};
    string s2{"cake"};
    bool bool_val = IsShorter(s1,s2);
    if(bool_val == true)
	cout << "true" << endl;
    else
	cout << "false" << endl;

    return 0;
}
inline bool IsShorter(string &str1_ref, string &str2_ref)
{
    return str1_ref.size() < str2_ref.size();
}

