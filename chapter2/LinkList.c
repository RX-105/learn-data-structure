#include "stdio.h"
#include "stdlib.h"
#include "LinkList.h"

LinkList LinkListHeadInit(LinkList list, int size)
{
    LNode *node;
    int idx;
    list = (LinkList)malloc(sizeof(LNode));
    list->next = NULL;
    for (int i = 0; i < size; i++)
    {
        node = (LNode *)malloc(sizeof(LNode));
        node->data = i;
        node->next = list->next;
        list->next = node;
    }
    return list;
}

void LinkListTailInit(LinkList list, int size)
{
    int idx;
    list = (LinkList)malloc(sizeof(LNode));
    LNode *node, *r = list;
    r->next = NULL;
    for (idx = 0; idx < size; idx++)
    {
        node = (LNode *)malloc(sizeof(LNode));
        node->data = idx;
        r->next = node;
        r = node;
    }
    r->next = NULL;
}

void LinkListPrint(LinkList list)
{
    LNode *node;
    if (list->next==NULL)
    {
        printf("LinkList: []\n");
        return;
    }
    node=list->next;
    printf("LinkList: [");
    while (node->next!=NULL)
    {
        printf("%d ", node->data);
        node=node->next;
    }
    printf("\b]\n");
}
