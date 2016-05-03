/*************************************************************************
	> File Name: obj_array.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Fri 30 Oct 2015 09:39:51 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

struct object
{
    //int ii[3];
    char data[3];
    //int ii[3];
};

int main()
{
    object obj_arr[3] = {{'a','b','c'},{'d','e','f'},{'g','h','i'}};
    object* cur = obj_arr;
    printf("%c %c\n", *((char*)cur+2), *(char*)(cur+2));
}

