/*************************************************************************
	> File Name: a++and++a.c
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Fri 16 Oct 2015 06:45:14 AM PDT
 ************************************************************************/

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>


int main()
{
    int a = 3;
    int i = 1;
    a+=a++*(a--);
    printf("%d\n",a);
    int j = i+++(i++)+(i++);
    printf("%d\n",j);

    return 0;
}
