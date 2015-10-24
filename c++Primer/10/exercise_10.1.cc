/*************************************************************************
	> File Name: exercise_10.1.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Thu 22 Oct 2015 05:35:56 PM PDT
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> vec = {1,2,3,3,1,3,5,6,7,3,8};
    auto cnt = count(vec.begin(),vec.end(),3);
    cout << cnt << endl;
    return 0;
}

