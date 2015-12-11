/*************************************************************************
	> File Name: uniform_real_distribution.cc
	> Author: Yikang Chen
	> Mail: sysucyk2010@163.com
	> Created Time: 2015年12月10日 星期四 21时34分12秒
 ************************************************************************/

#include <iostream>
#include <random>
using namespace std;

int main()
{
    default_random_engine e;
    uniform_real_distribution<double> u(0,2);
    for(int i = 0; i != 10; ++i){
        cout << u(e) << " ";
    }
    cout << endl;
    cout << u.min() << endl;
    cout << u.max() << endl;
    for(int i = 0; i != 10; ++i){
        cout << u(e) << " ";
    }
    cout << endl;
    u.reset();
    for(int i = 0; i != 10; ++i){
        cout << u(e) << " ";
    }
    cout << endl;
    return 0;
}
