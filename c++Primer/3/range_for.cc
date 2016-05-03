/*************************************************************************
	> File Name: range_for.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Mon 20 Jul 2015 06:53:28 PM PDT
 ************************************************************************/

#include <iostream>
using std::cout; using std::cin; using std::endl;
#include <string>
using std::string;
#include <cctype>

int main(void)
{
    string s1("hi,\"I\"- am SM.!~?;:\'\'");
    decltype(s1.size()) punct_num=0;
    for(auto c : s1)
	if(ispunct(c))
	    ++punct_num;
    cout << punct_num << " punctuation characters in " << s1 << endl;

    string s2="bIg bang!12345~\n";
    for(auto &ch : s2)
	ch = toupper(ch);
    cout << s2 ;
    char a = 'a';
    cout << (a = toupper(a)) << endl;

    return 0;
}

