/*************************************************************************
	> File Name: stack.c
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Thu 03 Sep 2015 07:21:26 AM PDT
 ************************************************************************/

#include <stdio.h>
#include "stack.h"
#include <stdlib.h>
int IsEmpty(Stack s)
{
    return s->next == NULL;
}

Stack CreateStack(void)
{
    Stack s = (Stack)malloc(sizeof(struct Node));
    if(s == NULL)
	printf("out of space\n");
    s->next = NULL;
    return s;
}

void Push(ElementType val_push, Stack s)
{
    PtrToNode temp_node = (PtrToNode)malloc(sizeof(struct Node));
    if(temp_node == NULL)
	printf("out of space\n");
    else
    {
	temp_node->val = val_push;
	temp_node->next = s->next;
	s->next = temp_node;
    }
}

void Pop(Stack s)
{
    if(IsEmpty(s))
    {
	printf("the stack is empty\n");
    }
    else
    {
	PtrToNode temp_ptr = s->next;
	s->next = s->next->next;
	free(temp_ptr);
    }
    return ;
}

ElementType GetTop(Stack s)
{
    if(IsEmpty(s))
	printf("empty stack\n");
    else
    {
	return s->next->val;
    }
    return 0;
}

void MakeEmpty(Stack s)
{
    if(IsEmpty(s))
	printf("stack is already empty\n");
    else
    {
	while(!IsEmpty(s))
	    Pop(s);
    }
}

int main(void)
{
    Stack my_stack = CreateStack();
    Push(3,my_stack);
    Push(5,my_stack);
    Push(7,my_stack);
    Push(9,my_stack);
    Push(31,my_stack);
    Push(33,my_stack);

    ElementType ret_val = GetTop(my_stack);
    printf("%d\n",ret_val);

    Pop(my_stack);
    Pop(my_stack);
    Pop(my_stack);
    ret_val = GetTop(my_stack);
    printf("%d\n",ret_val);

    MakeEmpty(my_stack);
    Pop(my_stack);

    return 0;
}
