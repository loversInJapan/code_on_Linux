/*************************************************************************
	> File Name: exercise_8.10.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Wed 16 Sep 2015 06:58:32 AM PDT
 ************************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
    vector<string> vec_in;
    ifstream in("e8-4.txt");
    string line, word;
    while(!in.eof())
    {
	getline(in, line);
	vec_in.push_back(line);
    }
    istringstream is;
    for(auto line : vec_in)
    {
	is.clear();
	is.str(line);
       // istringstream is(line);
	while(is >> word)
	    cout << word << endl;
    }

    return 0;
}
