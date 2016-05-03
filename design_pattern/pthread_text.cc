/*************************************************************************
	> File Name: pthread_text.cc
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Mon 30 Nov 2015 08:00:11 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <pthread.h>
using namespace std;

void* func(void* parg)
{
    cout << "this is a pthread" << endl;
    return nullptr;
}

int main()
{
    pthread_t pthid1 = 0, pthid2 = 0;
    pthread_create(&pthid1,nullptr,func,nullptr);
    pthread_join(pthid1,nullptr);
    return 0;
}
