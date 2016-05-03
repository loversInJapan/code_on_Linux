/*************************************************************************
	> File Name: word_transform.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Sat 17 Oct 2015 09:55:43 AM PDT
 ************************************************************************/

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
using namespace std;

//map<string,string> BuildMap(ifstream&);
//const string Transform(const map<string,string> &, const string &);

map<string,string> 
BuildMap(ifstream &map_file)
{
    string key;
    string value;
    map<string, string> rule_map;
    while(map_file >> key && getline(map_file, value)){
        if(value.size() > 1)
	    rule_map[key] = value.substr(1);
	else
	    throw runtime_error("no rule for " + key);
    }
    return rule_map;
}

const string 
Transform(const map<string, string> &trans_map, const string &word)
{
    auto target = trans_map.find(word);
    if(target == trans_map.cend())
	return word;
    else 
	return target->second;
}


void WordTransform(ifstream &map_file, ifstream &input)
{
    auto trans_map = BuildMap(map_file);
    string line;
    while(getline(input,line)){
	bool first_word = true;
	istringstream iss(line);
	string word;
	while(iss >> word){
	    if(first_word)
		first_word = false;
	    else
		cout << " ";
	    cout << Transform(trans_map, word);
	}
	cout << endl;
    }
}

int main(int argc, char **argv)
{
    //ifstream map_file(argv[1]);
    //ifstream input(argv[2]);
    ifstream map_file("map_file.txt");
    if(!map_file)
	throw runtime_error("no transformation file");
    ifstream input("input.txt");
    if(!input)
	throw runtime_error("no input file");
    WordTransform(map_file, input);
    return 0;
}
