/*************************************************************************
	> File Name: 1-9.c
	> Author: Yikang Chen
	> Mail: sysucyk2010@163.com
	> Created Time: 2016年01月06日 星期三 22时40分49秒
 ************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    printf("uid = %d, gid = %d\n", getuid(), getgid());

    exit(0);
}
