/*************************************************************************
	> File Name: size_of_point.c
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Fri 30 Oct 2015 09:47:37 PM CST
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

int main(void)
{
    int a[2][2] = {
	            {1,2},
		    {4,5} };
    int(*p)[2] = a;
    int *pp = &a[0][0];
    printf("%d\n", sizeof(pp));

    return 0;
}
