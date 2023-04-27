#ifndef LINK_LIST_H
#define LINK_LIST_H

#include "../commons.h"

typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

typedef struct DNode {
    ElemType data;
    struct DNode *prior, *next;
} DNode, *DLinkList;

LinkList LinkListHeadInit(LinkList list, int size, const int *initialContent);

LinkList LinkListTailInit(LinkList list, int size, const int *initialContent);

LinkList LinkListFromStdin(LinkList list);

void LinkListPrint(LinkList list);

DLinkList DLinkListTailInit(DLinkList list, int size, const int *initialContent);

void DLinkListPrint(DLinkList l);

void ReversePrint(LinkList l);

int LinkListLength(LinkList l);

// 章节习题从这里开始

void RemoveByValue(LinkList list, int x);

void RemoveMinimum(LinkList l);

void InPlaceReverse(LinkList l);

void InsertSort(LinkList l);

void RemoveByRange(LinkList l, int from, int to);

LNode *FindPublicNode(LinkList l1, LinkList l2);

void AscendPrintAndFree(LinkList l);

void SplitListByOdds(LinkList l1, LinkList l2);

void SplitList(LinkList l1, LinkList l2);

void Deduplicate(LinkList l);

void LinkListMerge(LinkList l1, LinkList l2);

LinkList GetPublicNodes(LinkList l1, LinkList l2);

int IsSublist(LinkList A, LinkList B);

int ContainsRing(LinkList l);

int HasLastIndex(LinkList l, int idx);

LNode *FindCommonSuffix(LinkList A, LinkList B);

void DeduplicateWithAbs(LinkList l, unsigned m);

void LinkListRearrange(LinkList l);

#endif
