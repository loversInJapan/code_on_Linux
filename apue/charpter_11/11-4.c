/*************************************************************************
	> File Name: 11-4.c
	> Author: Yikang Chen
	> Mail: sysucyk2010@163.com
	> Created Time: 2016年01月08日 星期五 17时36分25秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

struct foo
{
    int a, b, c, d;
};

void printfoo(const char* s, const struct foo* fp)
{
    printf("%s, pid = 0x%lx\n", s, pthread_self());
    printf("a = %d,", fp->a);
    printf("b = %d,", fp->b);
    printf("c = %d,", fp->c);
    printf("d = %d\n", fp->d);
}
void* thread_foo1(void* arg)
{
    struct foo data = {1,2,3,4};
    printfoo("thread 1", &data);
    pthread_exit((void*)&data);
}

void* thread_foo2(void* arg)
{
    printf("do nothing\n");
    pthread_exit((void*)0);
}

int main(void)
{
     int err;
     pthread_t tid1, tid2;
     struct foo* dp;

     err = pthread_create(&tid1, NULL, thread_foo1, NULL);
     if(err != 0)
         perror("can't create thread 1");
     err = pthread_join(tid1, (void*)&dp);
     if(err != 0)
         perror("can't join thread 1");
     sleep(1);

     printf("parent: starting thread 2\n");
     err = pthread_create(&tid2, NULL, thread_foo2, NULL);
     if(err != 0)
         perror("can't create thread 2");
     err = pthread_join(tid2, (void*)&dp);
     if(err != 0)
         perror("can't join thread 2");
     sleep(1);

    printfoo("parent: ", dp);

    return 0;
}

