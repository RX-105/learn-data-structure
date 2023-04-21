#ifndef LINK_LIST_H
#define LINK_LIST_H
#include "../commons.h"

typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

LinkList LinkListHeadInit(LinkList list, int size, int *initialContent);

LinkList LinkListTailInit(LinkList list, int size, int *initialContent);

void LinkListPrint(LinkList list);

void RemoveByValue(LinkList list, int x);

void ReversePrint(LinkList l);

void RemoveMinimum(LinkList l);

void InPlaceReverse(LinkList l);

void InsertSort(LinkList l);

#endif
