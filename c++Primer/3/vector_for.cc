/*************************************************************************
	> File Name: vector_for.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Tue 21 Jul 2015 06:58:34 AM PDT
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
    vector<int> ivec{1,2,3,4,5,6};
    for(auto &i : ivec)
	i*=i;
    for(auto &j : ivec)
	cout << j << endl;

    return 0;
}
