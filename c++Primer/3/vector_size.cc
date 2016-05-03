/*************************************************************************
	> File Name: vector_size.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Tue 21 Jul 2015 06:39:31 AM PDT
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;
 
int main(void)
{
    vector<int> ivec(10,1);
    ivec.push_back(2);
    //cout << ivec.size() << endl;

    vector<int> ivec2;
    int val;
    for(int i=0; i < 5; ++i)
	if(cin >> val)
	    ivec2.push_back(val);
    cout << ivec2.size() << endl;

    vector<string> svec;
    string word;
    while(cin >> word)
	svec.push_back(word);
    cout << svec.size() << endl;

    return 0;
}
