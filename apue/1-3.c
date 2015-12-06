/*************************************************************************
	> File Name: 1-3.c
	> Author: Yikang Chen
	> Mail: sysucyk2010@163.com
	> Created Time: 2015年12月06日 星期日 20时27分33秒
 ************************************************************************/

#include <stdio.h>
#include <dirent.h>
#include "apue.h"

int main()
{
    DIR *dp;
    struct dirent *dirp;
    if(argc != 2)
        err_quit("usage: ls directory_name");
    if((dp = opendir(argv[1])) == NULL)
        err_sys("can't open %s", argv[1]);

    while((dirp = readdir(dp)) != NULL)
        printf("%s\n", dirp->d_name);

    closedir(dp);
    exit(0);
}
