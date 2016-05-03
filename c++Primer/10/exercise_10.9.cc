/*************************************************************************
	> File Name: exercise_10.9.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Thu 22 Oct 2015 06:27:28 PM PDT
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

int main()
{
    string line;
    vector<string> words;
    getline(cin,line);
    istringstream iss(line);
    string word;
    while(iss >> word){
	words.push_back(word);
    }
    sort(words.begin(),words.end());
    for(auto print : words)
	cout << print << " ";
    cout << endl;
    auto end_uniq = unique(words.begin(), words.end());
    for(auto print : words)
	cout << print << " ";
    cout << endl;
    words.erase(end_uniq, words.end());
    for(auto print : words)
	cout << print << " ";
    cout << endl;
}
