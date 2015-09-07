/*************************************************************************
	> File Name: vector_exercise_3.17.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Tue 21 Jul 2015 07:13:11 AM PDT
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
    vector<string> svec;
    string word;
    while(cin >> word)
    {
	for(auto &ch : word)
	    ch = toupper(ch);
	svec.push_back(word);
    }
    for(auto &print : svec)
	cout << print << endl;

    return 0;
}
