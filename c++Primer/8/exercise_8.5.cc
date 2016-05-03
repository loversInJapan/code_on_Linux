/*************************************************************************
	> File Name: exercise_8.5.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Tue 15 Sep 2015 07:06:32 AM PDT
 ************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    vector<string> vec_str;
    string line;
    string file("e8-4.txt");
    ifstream input(file);
    if(!input)
    {
	cerr << "open file failed" << endl;
    }
    else
    {
	while(!input.eof())
	{
	    getline(input, line, ' ');
	    vec_str.push_back(line);
	}
    }

    for(auto print : vec_str)
        cout << print << endl;
    input.close();

    return 0;
}
