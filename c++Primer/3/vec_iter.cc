/*************************************************************************
	> File Name: vec_iter.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Tue 21 Jul 2015 11:40:32 PM PDT
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
    vector<int> ivec{1,2,3,4,5,6,7};
    for(auto iter=ivec.begin(); iter != ivec.end(); ++iter)
	(*iter)*=2;
    for(auto val : ivec)
	cout << val << endl;

    return 0;
}
