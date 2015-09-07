/*************************************************************************
	> File Name: list.c
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Tue 01 Sep 2015 01:18:54 AM PDT
 ************************************************************************/

#include <stdio.h>
#include "list.h"
#include <malloc.h>
#include <stdlib.h>
List CreatAList(unsigned int node_num)
{
    List my_list = (PtrToNode)malloc(sizeof(ListNode));
    my_list->val = node_num;
    my_list->next = NULL;
    Position cur_pos = my_list;
    for(int i=0; i < node_num; ++i)
    {
	cur_pos->next = (PtrToNode)malloc(sizeof(ListNode));
	cur_pos = cur_pos->next;
	cur_pos->val = 2*i;
	cur_pos->next = NULL;
    }
    return my_list;
}
List MakeEmpty(List L)
{
    Position cur_pos = L->next;
    while(L->next)
    {
	L->next = cur_pos->next;
	free(cur_pos);
	--L->val;
	cur_pos = L->next;
    }
    return L;
}
int IsEmpty(List L)
{
    return L->next == NULL;
}
int IsLast(Position pos, List L)
{
    return pos->next == NULL;
}
Position Find(ElementType target, List L)
{
    Position cur_pos = L->next;
    while(cur_pos!=NULL && cur_pos->val!=target)
	cur_pos = cur_pos->next;
    if(cur_pos)
        printf("found target node\n");
    else
	printf("not found target node\n");
    return cur_pos;
}
Position FindPreNode(ElementType target, List L)
{
    Position pos = L;
    while(pos->next != NULL && pos->next->val != target)
	pos = pos->next;
    if(pos->next != NULL)
    {
	printf("found previous node\n");
	return pos;
    }
    else
    {
	printf("not found previous node\n");
        return NULL;
    }
}
void Delete(ElementType target, List L)
{
    if(IsEmpty(L))
    {
	printf("delete failed\n");
    }
    else
    {
	Position cur_ptr = Find(target, L);
	if(!cur_ptr)
	{
	    printf("delete failed\n");
	    return ;
	}
        Position pre_ptr = FindPreNode(target, L);
	pre_ptr->next = cur_ptr->next;
	free(cur_ptr);
	--L->val;
	printf("delete successed\n");
    }
    return ;
}
void BackInsert(ElementType target, List L, Position pos)
{
    Position tar_node = malloc(sizeof(ListNode));
    if(tar_node == NULL)
	printf("out of space!\n");
    tar_node->val = target;
    tar_node->next = pos->next;
    pos->next = tar_node;
    ++(L->val);
    printf("insrt successed\n");
    return ;
}
void FrontInsert(ElementType target, List L, Position pre_pos)
{
    Position tar_node = malloc(sizeof(ListNode));
    if(tar_node == NULL)
	printf("out of space!\n");
    tar_node->val = target;
    tar_node->next = pre_pos->next;
    pre_pos->next = tar_node;
    ++(L->val);
    printf("insert successed!\n");
    return ;
}
void DeleteList(List L)
{
    MakeEmpty(L);
    free(L);
}
void PrintList(List L)
{
    if(IsEmpty(L))
    {
	printf("this list is empty\n");
	return ;
    }
    Position current = L;
    while(current)
    {
	printf("%d  ", current->val);
	current = current->next;
    }
    printf("\n");
}
