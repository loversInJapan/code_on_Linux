/*************************************************************************
	> File Name: default_random_engine.cc
	> Author: Yikang Chen
	> Mail: sysucyk2010@163.com
	> Created Time: 2015年12月10日 星期四 20时32分37秒
 ************************************************************************/

#include <iostream>
#include <random>
#include <ctime>
#include <vector>
using namespace std;

vector<unsigned> good_randVec()
{
    static default_random_engine e;
    static uniform_int_distribution<unsigned> u(0,9);
    vector<unsigned> ret;
    for(int i = 0; i < 100; ++i){
        ret.push_back(u(e));
    }
    return ret;
}
int main()
{
    default_random_engine e;
    uniform_int_distribution<unsigned> u(0,9);
    for(int i = 0; i < 10; ++i){
        cout << u(e) << " ";
    }
    cout << endl;
    cout << e.min() << endl;
    cout << e.max() << endl;
    vector<unsigned> v1(good_randVec());
    vector<unsigned> v2(good_randVec());
    cout << ((v1 == v2) ? "equal" : "not equal") << endl;

    default_random_engine e1;
    default_random_engine e2(2147483646);
    default_random_engine e3;
    e3.seed(time(0));
    default_random_engine e4;
    for(int i = 0; i != 10; ++i){
         if(e1() != e2())
             cout << "unseeded match at iteration: " << i << endl;
         if(e3() == e4())
             cout << "seeded differs at iteraton: " << i << endl;
    }
    return 0;
}
