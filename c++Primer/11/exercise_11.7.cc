/*************************************************************************
	> File Name: exercise_11.7.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Tue 13 Oct 2015 08:22:16 PM PDT
 ************************************************************************/

#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

void AddFamily(map<string, vector<string>> &families)
{
    string last_name;
    cout << "input a last name:" << endl;
    cin >> last_name;
    families[last_name];
}

void AddKids(map<string, vector<string>> &families, const string &last_name)
{
    string kid_name;
    cout << "input kid's name: " << endl;
    while(cin >> kid_name)
    {
	families[last_name].push_back(kid_name);
    }
}

int main()
{
    map<string, vector<string>> family;
    AddFamily(family);
    AddKids(family,"Huang");
    for(auto &pair : family)
    {
	cout << pair.first << "  ";
	for(auto &names : pair.second)
	    cout << names << " ";
        cout << endl;
    }

    return 0;
}
