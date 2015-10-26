/*************************************************************************
	> File Name: exercise_10.34.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Fri 23 Oct 2015 10:20:29 PM PDT
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{
    string str = "first,middle,last";
    auto word_end = find(str.begin(),str.end(),',');
    cout << string(str.begin(),word_end) << endl;
    auto rev_end = find(str.crbegin(),str.crend(),',');
    cout << string(str.crbegin(),rev_end) << endl;
    cout << string(rev_end.base(),str.cend()) << endl;

    vector<int> vec = {1,2,3,4};
    for(auto iter = vec.crbegin(); iter != vec.crend(); ++iter)
	cout << *iter << " ";
    cout << endl;

    return 0;
}
