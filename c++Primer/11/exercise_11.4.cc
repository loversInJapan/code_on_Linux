/*************************************************************************
	> File Name: exercise_11.4.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Tue 13 Oct 2015 07:07:48 PM PDT
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cctype>
#include <algorithm>
using namespace std;

int main()
{
    map<string, size_t> word_cnt;
    set<string> exclude = {"the","a","an","and","but","or","A","An","The","And","But","And"};
    //string alphabet = {'a','A','b','B','c','C','d','D','e','E','f','F','g','G','i','I','j'
	//                   ,'J','k','K','l','L','m','M','n','N','o','O','p','P','q','Q','r',
	//		  'R','s','S','t','T','u','U','v','V','w','W','x','X','y','Y','z','Z'};
    string alphabet = "aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ";
    string word;
    while(cin >> word)
    {
	if(exclude.find(word) == exclude.end())
	{
	    size_t beg = word.find_first_of(alphabet);
	    size_t end = word.find_last_of(alphabet);
	    word = word.substr(beg,end-beg+1);
	    transform(word.begin(), word.end(), word.begin(), ::tolower);
	    /*for(auto &ch : word)
	    {
		ch = tolower(ch);
	    }*/
	    ++word_cnt[word];
	}
    }
    for(auto &pair : word_cnt)
	cout << pair.first << ": " << pair.second << endl;

    return 0;
}

