/*************************************************************************
	> File Name: exercise_14.42.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Thu 12 Nov 2015 10:39:09 AM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<int> vec_int = {1,2,500,1000,1025,2002};
    vector<string> vec_str = {"pooh","pooh","notpooh","pooh"};
    greater<int> cmp_int;
    int cnt = 0;
    for(auto elem : vec_int){
        if(cmp_int(elem,1024))
	    ++cnt;
    }
    cout << "numbers of value greater than 1024 is " << cnt << '\n';
    not_equal_to<string> neq;
    for(auto s : vec_str){
	if(neq(s,"pooh")){
	    cout << s << endl;
	    break;
	}
    }
    multiplies<int> mul;
    //for_each(vec_int.begin(),vec_int.end(),mul(2));
    for(auto& val : vec_int){
	val = mul(val,2);
	cout << val << " ";
    }
    cout << endl;

    return 0;
}
