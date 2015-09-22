/*************************************************************************
	> File Name: exercise_9.2.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Sun 20 Sep 2015 04:42:34 AM PDT
 ************************************************************************/

#include <iostream>
#include <list>
#include <deque>
using namespace std;

int main()
{
    list<deque<int>> my_list;

    deque<int> que1{4,5,6};
    my_list.push_back(que1);

    deque<int> que2{1,2,3};
    my_list.push_front(que2);

    deque<int> que3{7,8,9};
    my_list.push_back(que3);

    for(const auto &que : my_list)
	for(const auto &elem : que)
	    cout << elem << " ";
    cout << endl;

    return 0;
}

