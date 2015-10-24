/*************************************************************************
	> File Name: exercise_10.11.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Thu 22 Oct 2015 07:49:40 PM PDT
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

bool IsShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

bool SizeBiggerThan5(const string &str)
{
    return str.size() >= 6;
}

int main()
{
    string line = "the quick red fox jumps over the slow red turtle";
    vector<string> words;
    //getline(cin,line);
    istringstream iss(line);
    string word;
    while(iss >> word){
	words.push_back(word);
    }
    sort(words.begin(),words.end());
    auto end_uniq = unique(words.begin(), words.end());
    words.erase(end_uniq, words.end());
    stable_sort(words.begin(),words.end(),
	    [](const string &s1, const string &s2) -> bool {return s1.size() < s2.size();});
    size_t sz = 5;
    auto first_size_5 = find_if(words.begin(),words.end(),
	    [sz](const string &str){return str.size() >= sz;});
    for_each(first_size_5, words.end(),
	    [](const string &str){cout << str << " ";});
    cout << endl;
    /*for(auto print : words)
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
    stable_sort(words.begin(),words.end(),IsShorter);
    for(auto print : words)
	cout << print << " ";
    cout << endl;
    auto end_bigger = partition(words.begin(), words.end(), SizeBiggerThan5);
    auto cur = words.begin();
    while(cur != end_bigger)
    {
	cout << *cur << " ";
	++cur;
    }
    cout << endl;
    auto res = find_if(words.begin(),words.end(),SizeBiggerThan5);
    if(res != words.end())
    	cout << *res << endl;
    else
	cout << "not found" << endl;*/

    return 0;
}
