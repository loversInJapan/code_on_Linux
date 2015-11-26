/*************************************************************************
	> File Name: exercise_16.4.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Thu 26 Nov 2015 04:46:16 PM CST
 ************************************************************************/

#include <iostream>
#include <list>
#include <vector>
#include <string>
//#include <iterator>
using namespace std;

template <typename IT, typename V>
IT find(IT beg, IT end, const V& v )
{
    while(beg != end){
	if(*beg == v)
	    return beg;
	++beg;
    }
    return end;
}

int main()
{
    vector<int> vec = {1,2,3,4,5,6};
    list<string> ls = {"a","hello","hell"};
    //auto ret = find(vec.begin(), vec.end(), 7);
    auto ret = find(ls.begin(), ls.end(), "a");
    if(ret != ls.end())
	cout << *ret << endl;
    else
	cout << "not found" << endl;

    return 0;
}
