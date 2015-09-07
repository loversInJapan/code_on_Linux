/*************************************************************************
	> File Name: stack.h
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Thu 03 Sep 2015 07:14:13 AM PDT
 ************************************************************************/

#ifndef STACK_H_
#define STACK_H_
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;
typedef int ElementType;

int IsEmpty(Stack s);
Stack CreateStack(void);
void DisposeStack(Stack s);
void MakeEmpty(Stack s);
void Push(ElementType x, Stack s);
ElementType GetTop(Stack s);
void Pop(Stack s);
#endif

struct Node
{
    ElementType val;
    PtrToNode next;
};
