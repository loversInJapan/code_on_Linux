/*************************************************************************
	> File Name: exercise_9.41.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Sat 10 Oct 2015 12:11:30 AM PDT
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<char> vec = {'h','e','l','l','o',' ','w','o','r','l','d'};
    string cmp = "01234l67o9";
    string str;
    str.assign(vec.begin(),vec.end());
    cout << str << endl;
    auto pos1 = cmp.find_first_not_of(str);
    auto pos2 = cmp.find_last_not_of(str);
    cout << pos1 << " " << pos2 << endl;

    return 0;
}
