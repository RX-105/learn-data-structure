#ifndef LINK_LIST_H
#define LINK_LIST_H
#include "../commons.h"

typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

LinkList LinkListHeadInit(LinkList list, int size, const int *initialContent);

LinkList LinkListTailInit(LinkList list, int size, const int *initialContent);

void LinkListPrint(LinkList list);

void RemoveByValue(LinkList list, int x);

void ReversePrint(LinkList l);

int LinkListLength(LinkList l);

void RemoveMinimum(LinkList l);

void InPlaceReverse(LinkList l);

void InsertSort(LinkList l);

void RemoveByRange(LinkList l, int from, int to);

LNode* FindPublicNode(LinkList l1, LinkList l2);

void AscendPrintAndFree(LinkList l);

void SplitListByOdds(LinkList l1, LinkList l2);

void SplitList(LinkList l1, LinkList l2);

void Deduplicate(LinkList l);

void LinkListMerge(LinkList l1, LinkList l2);

LinkList GetPublicNodes(LinkList l1, LinkList l2);

#endif
