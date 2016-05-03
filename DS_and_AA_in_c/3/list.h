/*************************************************************************
	> File Name: list.h
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Tue 01 Sep 2015 12:51:33 AM PDT
 ************************************************************************/

#ifndef LIST_H_
#define LIST_H_
struct Node;
typedef struct Node ListNode;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
typedef int ElementType;

List CreatAList(unsigned int node_num);
List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(Position pos, List L);
Position Find(ElementType target, List L);
void Delete(ElementType target, List L);
Position FindPreNode(ElementType target, List L);
void BackInsert(ElementType target, List L, Position pos);
void FrontInsert(ElementType target, List L, Position pre_pos);
void BackInsert(ElementType target, List L, Position pos);
void DeleteList(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position pos);
void PrintList(List L);
#endif

struct Node
{
    ElementType val;
    Position next;
};
