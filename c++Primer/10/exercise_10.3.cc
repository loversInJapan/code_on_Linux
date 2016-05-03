/*************************************************************************
	> File Name: exercise_10.3.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Thu 22 Oct 2015 05:46:49 PM PDT
 ************************************************************************/

#include <iostream>
#include <vector>
#include <numeric>
#include <string>
using namespace std;

int main()
{
    vector<int> vec = {1,2,3,4,5};
    auto sum = accumulate(vec.begin(),vec.end()-1,0);
    cout << sum << endl;
    vector<double> dvec = {1.1,2.1,1.4,2.3};
    auto dsum = accumulate(dvec.cbegin(),dvec.cend(),0.0);
    cout << dsum << endl;

    vector<const char*> strs = {"name","sex","job"};
    vector<const char*> fix = {"name","sex","job"};
    auto res = equal(strs.cbegin(),strs.cend(),fix.cbegin());
    cout << (res ? "equal" : "unequal") << endl;

    fill_n(back_inserter(vec), 5, 1);
    for(auto ints : vec)
	cout << ints << " ";
    cout << endl;

    return 0;
}
