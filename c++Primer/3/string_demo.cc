/*************************************************************************
	> File Name: string_demo.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Mon 20 Jul 2015 07:21:35 AM PDT
 ************************************************************************/

#include <iostream>
using namespace std;
int main(void)
{
    /*
    string s1;
    while(cin >> s1)
	cout << s1 << endl;
    */
    string line;
    while(getline(cin,line))
	if(!line.empty())
	    cout << line << endl;
    
    string s1="hello, ", s2("world!");
    string s3;
    s3 = s1+s2+" "+"how do you do!";
    cout << s3 << endl;
    s1+=s2;
    cout << s1 << endl;
    //string error;
    //error = "string"+'a';
    s3 = s1+"haha "+", ";

    return 0;
}
