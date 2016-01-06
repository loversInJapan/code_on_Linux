/*************************************************************************
	> File Name: 1-4.c
	> Author: Yikang Chen
	> Mail: sysucyk2010@163.com
	> Created Time: 2016年01月06日 星期三 20时41分02秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define BUFFSIZE 2048

int main(void)
{
    int n;
    char buf[BUFFSIZE];
    while((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
        if(write(STDOUT_FILENO, buf, n) != n)
            perror("write wrong");

    if(n < 0)
        perror("read error");

    return 0;
}
