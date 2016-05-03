/*************************************************************************
	> File Name: exercise_12.26.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Sat 31 Oct 2015 06:13:51 PM CST
 ************************************************************************/

#include <iostream>
#include <memory>
#include <vector>
#include <string>
using namespace std;

int main()
{
    vector<string> src(5,"cba");
    //auto b = 
    allocator<string> alloc;
    auto p = alloc.allocate(src.size()*2);
    auto q = uninitialized_copy(src.begin(),src.end(),p);
    //auto e = 
    uninitialized_fill_n(q,src.size(),"nba");
    auto cur = p;
    for(int i = 0; i < src.size()*2; ++i)
	cout << *cur++ << endl;
    auto del = p;
    int i = 0;
    while(i < src.size()*2)
    {
	alloc.destroy(del++);
	++i;
    }
    alloc.deallocate(p,src.size()*2);
    return 0;
}
