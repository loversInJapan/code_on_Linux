/*************************************************************************
	> File Name: 1-11.c
	> Author: Yikang Chen
	> Mail: sysucyk2010@163.com
	> Created Time: 2016年01月07日 星期四 09时48分42秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAXLINE 1024

static void sig_int(int);

int main()
{
    char buf[MAXLINE];
    pid_t pid;
    int status;

    if(signal(SIGINT,sig_int) == SIG_ERR)
        perror("signal errror");

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

static void sig_int(int sig)
{
     printf("interrupte\n");
}
