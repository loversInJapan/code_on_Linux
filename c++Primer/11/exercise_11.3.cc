/*************************************************************************
	> File Name: exercise_11.3.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Tue 13 Oct 2015 06:39:06 PM PDT
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main()
{
    map<string, size_t> word_cnt;
    set<string> exclude = {"the","a","an","and","but","or","A","An","The","And","But","And"};
    string word;
    while(cin >> word)
    {
	if(exclude.find(word) == exclude.end())
	    ++word_cnt[word];
    }
    for(auto &pair : word_cnt)
	cout << pair.first << ": " << pair.second << endl;

    return 0;
}

