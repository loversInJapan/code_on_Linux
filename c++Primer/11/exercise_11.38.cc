/*************************************************************************
	> File Name: exercise_11.38.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Tue 20 Oct 2015 08:00:01 PM PDT
 ************************************************************************/

#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>
#include <fstream>
using namespace std;

void 
word_count()
{
    unordered_map<string, unsigned> cnt_map;
    string word;
    cout << "/............input............./" << endl;
    while(cin >> word)
	++cnt_map[word];
    cout << "/............................../" << endl;
    cout << "/............output............./" << endl;
    for(auto &out : cnt_map)
	cout << out.first << " occurs " << 
	    out.second << ((out.second > 1) ? " times" : " time") << endl;
    cout << "/............................../" << endl;
}

unordered_map<string, string>
build_map(ifstream &rules)
{
    unordered_map<string, string> trans_map;
    string key;
    string value;
    while(rules >> key && getline(rules,value))
    {
	if(value.size() > 0)
	    trans_map[key] = value.substr(1);
	else
	    throw runtime_error("no rule for " + key);
    }
    return trans_map;
}

const string
transform(const string &src, unordered_map<string,string> &rules)
{
    string des_str;
    auto map_it = rules.find(src);
    if(map_it != rules.end())
	return map_it->second;
    return src;
}

void word_transform(ifstream &config, ifstream &input)
{
    auto rules_map = build_map(config);
    string text;
    while(getline(input,text))
    {
	istringstream iss(text);
	string word;
	bool first_word = true;
        while(iss >> word)
	{
	    if(first_word)
		first_word = false;
	    else
		cout << " ";
	    cout << transform(word, rules_map);
	}
	cout << endl;
    }
}

int main()
{
    //word_count();
    ifstream config("map_file.txt");
    ifstream input("input.txt");
    word_transform(config, input);

    return 0;
}

