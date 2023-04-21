#include "stdio.h"
#include "stdlib.h"
#include "LinkList.h"

LinkList LinkListHeadInit(LinkList list, int size, int *initialContent)
{
    LNode *node;
    int idx;
    list = (LinkList)malloc(sizeof(LNode));
    list->next = NULL;
    for (int i = 0; i < size; i++)
    {
        node = (LNode *)malloc(sizeof(LNode));
        node->data = initialContent[i];
        node->next = list->next;
        list->next = node;
    }
    return list;
}

LinkList LinkListTailInit(LinkList list, int size, int *initialContent)
{
    int idx;
    list = (LinkList)malloc(sizeof(LNode));
    LNode *node, *r = list;
    r->next = NULL;
    for (idx = 0; idx < size; idx++)
    {
        node = (LNode *)malloc(sizeof(LNode));
        node->data = initialContent[idx];
        r->next = node;
        r = node;
    }
    r->next = NULL;
    return list;
}

void LinkListPrint(LinkList list)
{
    LNode *node;
    if (list->next == NULL)
    {
        printf("LinkList: []\n");
        return;
    }
    node = list->next;
    printf("LinkList: [");
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\b]\n");
}

void LinkListDestroy(LinkList list)
{
    if (list->next != NULL)
        LinkListDestroy(list->next);
    free(list);
}

// 第二章 综合应用题

// 01
void RemoveByValue(LinkList list, int x)
{
    if (list == NULL)
        return;
    if (list->data == x)
    {
        LNode *next = list->next;
        list->data = list->next->data;
        list->next = list->next->next;
        free(next);
        RemoveByValue(list, x);
    }
    else
        RemoveByValue(list->next, x);
}

// 03 
void ReversePrint(LinkList l)
{
    if (l->next == NULL)
        printf("%d ", l->data);
    else
    {
        ReversePrint(l->next);
        printf("%d ", l->data);
    }
}

// 04
void RemoveMinimum(LinkList l) {
    LNode *minNode = l->next, *p = l->next->next;
    while (p != NULL) {
        if (p->data < minNode->data)
            minNode = p;
        p = p->next;
    }
    if (minNode->next == NULL){
        free(minNode);
        minNode = NULL;
    } else{
        p = minNode->next;
        minNode->data = p->data;
        minNode->next = p->next;
        free(p);
    }
}

// 05 就地逆置
void InPlaceReverse(LinkList l) {
    LNode *p = l->next, *next = NULL;
    l->next = NULL;
    while (p!=NULL){
        next = p->next;
        p->next = l->next;
        l->next = p;
        p=next;
    }
}


// 06 插入排序法
void InsertSort(LinkList l) {
    // 空间复杂度为O(0)，时间复杂度为O(n^2)。为了达到更快的速度，可以把数据复制到一个
    // 线性随机存储结构（比如数组）然后再进行快排（或堆排），可以达到O(nlogn)的时间复杂度
    LNode *curr = l->next, *next = curr->next, *prev = NULL;
    curr->next = NULL;
    curr = next;
    while (curr != NULL) {
        next = curr->next;
        prev = l;
        while (prev->next!=NULL&&curr->data>prev->next->data)
            prev = prev->next;
        curr->next = prev->next;
        prev->next = curr;
        curr = next;
    }
}
