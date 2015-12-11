/*************************************************************************
	> File Name: normal_distribution.cc
	> Author: Yikang Chen
	> Mail: sysucyk2010@163.com
	> Created Time: 2015年12月10日 星期四 21时59分28秒
 ************************************************************************/

#include <iostream>
#include <random>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    normal_distribution<> n(6,2.5);
    default_random_engine e;
    vector<unsigned> vals(10);
    for(int i = 0; i != 300; ++i){
        unsigned v = lround(n(e));
        if(v < vals.size())
            ++vals[v];
    }
    for(int j = 0; j != vals.size(); ++j)
        cout << j << ": " << string(vals[j], '*') << endl;

    return 0;
}
