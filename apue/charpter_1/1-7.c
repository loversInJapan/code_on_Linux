/*************************************************************************
	> File Name: 1-7.c
	> Author: Yikang Chen
	> Mail: sysucyk2010@163.com
	> Created Time: 2016年01月06日 星期三 21时56分30秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAXLINE 1024

int main()
{
    char buf[MAXLINE];
    pid_t pid;
    int status;

    printf("%%"); // printf requires %% to print %
    while(fgets(buf, MAXLINE, stdin) != NULL){
        if(buf[strlen(buf) - 1] == '\n')
            buf[strlen(buf) - 1] = 0;

        if((pid = fork()) < 0){
            perror("fork error");
        }else if(pid == 0){
            execlp(buf, buf, (char*)0);
            exit(127);
        }

        if((pid = waitpid(pid, &status, 0)) < 0)
            perror("waitpid error");
        printf("%%");
    }

    return 0;
}
