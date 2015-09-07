/*************************************************************************
	> File Name: exercise_6.27.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Sat 15 Aug 2015 08:23:46 AM PDT
 ************************************************************************/

#include <iostream>
#include <initializer_list>
using namespace std;
int integer_sum(initializer_list<int> list)
{
    int ret=0;
    for(auto &elem : list)
	ret+=elem;
    return ret;
}
int main()
{
    int my_sum = integer_sum({1,2,3,4,5,6,7,8,9,10});
    cout << my_sum << endl;
    return 0;
}
