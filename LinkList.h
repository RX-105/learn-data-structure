#include "commons.h"

typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

LinkList LinkListHeadInit(LinkList list, int size);

void LinkListTailInit(LinkList list, int size);

void LinkListPrint(LinkList list);
