/*************************************************************************
	> File Name: main.c
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Tue 01 Sep 2015 01:58:50 AM PDT
 ************************************************************************/

#include <stdio.h>
#include "list.h"
int main()
{
    List my_list = CreatAList(5);
    PrintList(my_list);
    Position found = Find(4, my_list);
    Position pre_node = FindPreNode(8,my_list);
    BackInsert(5,my_list,found);
    PrintList(my_list);
    FrontInsert(7,my_list,pre_node);
    PrintList(my_list);
    Delete(5,my_list);
    PrintList(my_list);
    MakeEmpty(my_list);
    PrintList(my_list);
    DeleteList(my_list);
    return 0;
}
