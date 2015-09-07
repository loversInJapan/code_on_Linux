/*************************************************************************
	> File Name: doubly_linked_list.c
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Tue 01 Sep 2015 05:39:06 AM PDT
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;
typedef struct DLNode
{
    struct DLNode *pre_ptr;
    ElementType val;
    struct DLNode *back_ptr;
}Node, *PtrToNode;
typedef PtrToNode List;

List CreatADoublyList(unsigned int cnt)
{
    PtrToNode my_DList = (PtrToNode)malloc(sizeof(Node));
    my_DList->val = cnt;
    my_DList->pre_ptr = NULL;
    my_DList->back_ptr = NULL;
    PtrToNode cur_pos = my_DList;
    for(int i=0; i < cnt; ++i)
    {
	PtrToNode new_node = (PtrToNode)malloc(sizeof(Node));
	new_node->val = 3*i;
	cur_pos->back_ptr = new_node;
	new_node->pre_ptr = cur_pos;
	new_node->back_ptr = cur_pos->back_ptr;
	cur_pos = new_node;
    }
    return my_DList;
}
int main()
{
    PtrToNode my_list = CreatADoublyList(4);
    PtrToNode search_ptr = my_list->back_ptr->back_ptr->back_ptr;
    printf("%d\n",search_ptr->pre_ptr->val);
    return 0;
}
