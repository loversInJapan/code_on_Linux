/*************************************************************************
	> File Name: exercise_10.29.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Fri 23 Oct 2015 08:33:13 PM PDT
 ************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
using namespace std;

int main()
{
    ostream_iterator<string> out_it_str(cout, " ");
    ifstream ifs("test.txt");
    istream_iterator<string> in_it_str(ifs), eof;
    vector<string> vec(in_it_str, eof);
    copy(vec.begin(),vec.end(),out_it_str);
    cout << endl;
    return 0;
}
