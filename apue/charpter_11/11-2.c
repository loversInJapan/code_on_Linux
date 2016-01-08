/*************************************************************************
	> File Name: 11-2.c
	> Author: Yikang Chen
	> Mail: sysucyk2010@163.com
	> Created Time: 2016年01月08日 星期五 16时49分20秒
 ************************************************************************/

#include <stdio.h>
#include <errno.h>
#include <pthread.h>
#include <unistd.h>

void* pthread_func1(void* arg)
{
    printf("pthread_func1 is runing\n");
    pthread_exit((void*)1);
}

void* pthread_func2(void* arg)
{
    printf("pthread_func2 is excuting\n");
    pthread_exit((void*)2);
}

int main(void)
{
    pthread_t tid1, tid2;
    int err;
    void* tret;

    if((err = pthread_create(&tid1, NULL, pthread_func1, NULL)) != 0)
        // which thread will run first is unpredictable
        perror("can't create pthread_1");
    //sleep(1);
    if((err = pthread_create(&tid2, NULL, pthread_func2, NULL)) != 0)
        perror("can't create pthread_2");
    err = pthread_join(tid1, &tret);
    if(err != 0)
        perror("can't join thread 1");
    printf("exit thread 1 with code: %d\n", (int)tret);

    err = pthread_join(tid2, &tret);
    if(err != 0)
        perror("can't join thread 2");
    printf("exit thread 2 with code: %d\n", (int)tret);
    return 0;
}

