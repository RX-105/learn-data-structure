#include "stdio.h"
#include "stdlib.h"
#include "LinkList.h"

LinkList LinkListHeadInit(LinkList list, int size, const int *initialContent) {
    LNode *node;
    int idx;
    list = (LinkList) malloc(sizeof(LNode));
    list->next = NULL;
    for (int i = 0; i < size; i++) {
        node = (LNode *) malloc(sizeof(LNode));
        node->data = initialContent[i];
        node->next = list->next;
        list->next = node;
    }
    return list;
}

LinkList LinkListTailInit(LinkList list, int size, const int *initialContent) {
    int idx;
    list = (LinkList) malloc(sizeof(LNode));
    LNode *node, *r = list;
    r->next = NULL;
    for (idx = 0; idx < size; idx++) {
        node = (LNode *) malloc(sizeof(LNode));
        node->data = initialContent[idx];
        r->next = node;
        r = node;
    }
    r->next = NULL;
    return list;
}

void LinkListPrint(LinkList list) {
    LNode *node;
    if (list->next == NULL) {
        printf("LinkList: []\n");
        return;
    }
    node = list->next;
    printf("LinkList: [");
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\b]\n");
}

void LinkListDestroy(LinkList list) {
    if (list->next != NULL)
        LinkListDestroy(list->next);
    free(list);
}

int LinkListLength(LinkList l) {
    int length = 0;
    LNode *p = l;
    while (p->next != NULL) {
        length++;
        p = p->next;
    }
    return length;
}

// 第二章 综合应用题

// 01
void RemoveByValue(LinkList list, int x) {
    if (list == NULL)
        return;
    if (list->data == x) {
        LNode *next = list->next;
        list->data = list->next->data;
        list->next = list->next->next;
        free(next);
        RemoveByValue(list, x);
    } else
        RemoveByValue(list->next, x);
}

// 03 
void ReversePrint(LinkList l) {
    if (l->next == NULL)
        printf("%d ", l->data);
    else {
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
    if (minNode->next == NULL) {
        free(minNode);
        minNode = NULL;
    } else {
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
    while (p != NULL) {
        next = p->next;
        p->next = l->next;
        l->next = p;
        p = next;
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
        while (prev->next != NULL && curr->data > prev->next->data)
            prev = prev->next;
        curr->next = prev->next;
        prev->next = curr;
        curr = next;
    }
}

// 07 删除值介于指定范围内的节点
void RemoveByRange(LinkList l, int from, int to) {
    LNode *p = l->next, *t = NULL;
    while (p != NULL) {
        if (p->data > from && p->data < to) {
            t = p->next;
            p->data = t->data;
            p->next = t->next;
            free(t);
        } else {
            p = p->next;
        }
    }
}

// 08 查找公共节点
// 考虑到内存中完全一样的公共节点对象组成的链表不容易构造，因此这个解法中使用
// 值相等来判断
LNode *FindPublicNode(LinkList l1, LinkList l2) {
    // 两个表的遍历起点到终点距离应该是相同的，那么就以短表的长度作为共同起点
    // 然后同步遍历
    LNode *p1 = l1->next, *p2 = l2->next;
    int len1 = LinkListLength(l1), len2 = LinkListLength(l2), idx = 0;
    if (len1 < len2) {
        while (idx < len2 - len1) {
            p2 = p2->next;
            idx++;
        }
    }
    if (len1 > len2) {
        while (idx < len1 - len2) {
            p1 = p1->next;
            idx++;
        }
    }
    while (p1 != NULL) {
        if (p1->data == p2->data) // 如果想要判断完全相等，条件改为(p1 == p2)
            return p1;
        else {
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    return NULL;
}

// 09
// 升序输出所有结点的值，然后释放其内存空间。不允许使用数组作为辅助空间
void AscendPrintAndFree(LinkList l) {
    // 先做一遍插入排序，随后输出并释放内存
    InsertSort(l);
    LNode *p = l->next, *next = NULL;
    while (p != NULL) {
        next = p->next;
        printf("%d ", p->data);
        free(p);
        p = next;
    }
}

// 10
// 将给定的表拆分成两个表。下标为奇数和下标为偶数的元素放入分别的表，且保持原有顺序不变。
void SplitListByOdds(LinkList l1, LinkList l2) {
    // 保持原有顺序不变意思就是用尾插法创建新链表
    LNode *p = l1->next, *t = NULL;
    LNode *h1 = l1, *h2 = l2;
    l1->next = NULL;
    l2->next=NULL;
    int idx = 0;
    while (p != NULL) {
        t=p->next;
        if (idx%2==0){
            p->next=h1->next;
            h1->next = p;
            h1=p;
        } else {
            p->next=h2->next;
            h2->next = p;
            h2=p;
        }
        p=t;
        idx++;
    }
    h1->next = NULL;
    h2->next = NULL;
}

// 11
// 将[a1, b1, a2, b2, ..., an, bn]拆分成[a1, a2, ..., an]和[bn, ..., b2, b1]
void SplitList(LinkList l1, LinkList l2) {
    // 思路和上一道题类似，只不过a表用尾插法，b表用头插法
    int idx = 0;
    LNode *p1 = l1->next, *h1 = l1, *next;
    l1->next = NULL; // 断开头节点和下一个节点，产生新的链表
    l2->next = NULL;
    while (p1!=NULL){
        next = p1->next;
        if (idx%2==0){
            // 用尾插法加入到l1中
            p1->next = h1->next;
            h1->next = p1;
            h1=p1;
        } else {
            // 用头插法加入到l2中
            p1->next = l2->next;
            l2->next = p1;
        }
        p1=next;
        idx++;
    }
}

// 12
// 列表去重
void Deduplicate(LinkList l) {
    LNode *p = l->next;
    while (p!=NULL){
        if (p->next!=NULL && p->next->data == p->data){
            LNode *t = p->next;
            p->next = t->next;
            free(t);
        } else {
            p=p->next;
        }
    }
}

// 13
// 合并两个有序的链表，新链表使用原来的节点，数据仍然保持有序
void LinkListMerge(LinkList l1, LinkList l2) {
    // 既然想要保持原来顺序，就得在新表上用尾插法
    LNode *p1 = l1->next, *p2 = l2->next;
    LNode *head = l1, *t;
    l1->next = NULL;
    // ???
    while (p1!=NULL && p2!=NULL) {
        if (p1->data <= p2->data) {
            t = p1->next;
            p1->next = head->next;
            head->next = p1;
            head = p1;
            p1 = t;
        } else {
            t = p2->next;
            p2->next = head->next;
            head->next = p2;
            head = p2;
            p2=t;
        }
    }
    // 检查剩余的元素，并插入到新表
    while (p1!=NULL) {
        t = p1->next;
        p1->next = head->next;
        head->next = p1;
        head = p1;
        p1 = t;
    }
    while (p2!=NULL) {
        t = p2->next;
        p2->next = head->next;
        head->next = p2;
        head = p2;
        p2=t;
    }
}

// 14
// 从两个升序排序的链表中提取公共节点（只需要值相等，不需要内存地址相等）
LinkList GetPublicNodes(LinkList l1, LinkList l2) {
    LinkList out = (LinkList) malloc(sizeof(LinkList));
    LNode *p1 = l1->next, *p2 = l2->next, *pO = out;
    out->next = NULL;
    while (p1!=NULL && p2!=NULL) {
        if (p1->data == p2->data) {
            LNode *node = (LNode*) malloc(sizeof(LNode));
            node->data = p1->data;
            node->next = pO->next;
            pO->next = node;
            pO=node;
            p1=p1->next;
            p2=p2->next;
        } else if (p1->data > p2->data) {
            p2=p2->next;
        } else {
            p1=p1->next;
        }
    }
    return out;
}


