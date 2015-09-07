/*************************************************************************
	> File Name: vec_arr.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Wed 22 Jul 2015 01:21:36 AM PDT
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
    int ia[] = {1,2,3,4,5,6};
    vector<int> ivec(ia, ia+4);
    for(auto val : ivec)
	cout << val << endl;

    return 0;
}

