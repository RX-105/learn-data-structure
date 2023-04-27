#include <string.h>
#include "stdio.h"
#include "stdlib.h"
#include "LinkList.h"

LinkList LinkListHeadInit(LinkList list, int size, const int *initialContent) {
    LNode *node;
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

LinkList LinkListFromStdin(LinkList list) {
    int val;
    list = (LinkList) malloc(sizeof(LinkList));
    LNode *rear = list, *node;
    rear->next = NULL;
    scanf("%d", &val);
    while (val != -1) {
        node = (LNode *) malloc(sizeof(LNode *));
        node->data = val;
        rear->next = node;
        rear = node;
        scanf("%d", &val);
    }
    rear->next = NULL;
    return list;
}

DLinkList DLinkListTailInit(DLinkList list, int size, const int *initialContent) {
    list = (DLinkList) malloc(sizeof(DLinkList));
    list->next = NULL;
    list->prior = NULL;
    DNode *p = list;
    for (int i = 0; i < size; ++i) {
        DNode *node = (DNode *) malloc(sizeof(DNode *));
        node->data = initialContent[i];
        node->next = p->next;
        node->prior = p;
        p->next = node;
        p = node;
    }
    return list;
}

void DLinkListPrint(DLinkList l) {
    DNode *p = l->next;
    if (l->next == NULL) {
        printf("DLinkList: []\n");
        return;
    }
    p = l->next;
    printf("DLinkList: [");
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\b]\n");
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
    l2->next = NULL;
    int idx = 0;
    while (p != NULL) {
        t = p->next;
        if (idx % 2 == 0) {
            p->next = h1->next;
            h1->next = p;
            h1 = p;
        } else {
            p->next = h2->next;
            h2->next = p;
            h2 = p;
        }
        p = t;
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
    while (p1 != NULL) {
        next = p1->next;
        if (idx % 2 == 0) {
            // 用尾插法加入到l1中
            p1->next = h1->next;
            h1->next = p1;
            h1 = p1;
        } else {
            // 用头插法加入到l2中
            p1->next = l2->next;
            l2->next = p1;
        }
        p1 = next;
        idx++;
    }
}

// 12
// 列表去重
void Deduplicate(LinkList l) {
    LNode *p = l->next;
    while (p != NULL) {
        if (p->next != NULL && p->next->data == p->data) {
            LNode *t = p->next;
            p->next = t->next;
            free(t);
        } else {
            p = p->next;
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
    while (p1 != NULL && p2 != NULL) {
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
            p2 = t;
        }
    }
    // 检查剩余的元素，并插入到新表
    while (p1 != NULL) {
        t = p1->next;
        p1->next = head->next;
        head->next = p1;
        head = p1;
        p1 = t;
    }
    while (p2 != NULL) {
        t = p2->next;
        p2->next = head->next;
        head->next = p2;
        head = p2;
        p2 = t;
    }
}

// 14
// 从两个升序排序的链表中提取公共节点（只需要值相等，不需要内存地址相等）
LinkList GetPublicNodes(LinkList l1, LinkList l2) {
    LinkList out = (LinkList) malloc(sizeof(LinkList));
    LNode *p1 = l1->next, *p2 = l2->next, *pO = out;
    out->next = NULL;
    while (p1 != NULL && p2 != NULL) {
        if (p1->data == p2->data) {
            LNode *node = (LNode *) malloc(sizeof(LNode));
            node->data = p1->data;
            node->next = pO->next;
            pO->next = node;
            pO = node;
            p1 = p1->next;
            p2 = p2->next;
        } else if (p1->data > p2->data) {
            p2 = p2->next;
        } else {
            p1 = p1->next;
        }
    }
    return out;
}


// 15
// 这道题和上一道题类似，略

// 16
// 判断B表是否是A表的连续子序列
int IsSublist(LinkList A, LinkList B) {
    // 类似于字符串匹配算法，不过这里就不用KMP了
    // 对两个表分别设置工作指针，对A表额外设置一个回落指针
    // 同时对两个表进行遍历，判断内容相等时同步后移，不相等时A工作指针设置为回落指针的下一个节点（同时回落指针后移）
    // 然后将B工作指针设置为开头，再次开始遍历，直到B工作指针抵达末端
    // 结束时判断B工作指针是否指向最后一个节点，以此作为判断条件
    LNode *pA = A->next, *pB = B->next, *fb = A->next;
    while (pA && pB) {
        if (pA->data == pB->data) {
            pA = pA->next;
            pB = pB->next;
        } else {
            fb = fb->next;
            pA = fb;
            pB = B->next;
        }
    }
    if (pB == NULL) {
        return 1;
    } else {
        return 0;
    }
}

// 21
// 判断给定的单链表是否存在环。环指的是尾节点指向链表中的某个节点，正常情况下它应该指向NULL
int ContainsRing(LinkList l) {
    LNode *slow = l, *fast = l;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return 1;
        }
    }
    if (fast == NULL && fast->next == NULL) {
        return 0;
    } else {
        return -1;
    }
}

// 22 2009统考真题
// 给定单链表的头指针，查找链表中倒数第idx位置上的元素，如果存在就输出其值并返回1，否则返回0
// 不能改变链表结构，要求算法尽可能高效
int HasLastIndex(LinkList l, int idx) {
    // 1. 通过数组来实现对链表的随机访问
    // 2. 遍历整个链表，并把数值保存到一个数组中。遍历完毕后，判断链表长度是否满足idx，如果满足，则输出下标length-idx上的元素
    // 3. 如下
//    int data[0x7fff] = {0};
//    LNode *p = l->next;
//    int length = 0;
//    while (p) {
//        data[length++]=p->data;
//        p=p->next;
//    }
//    if (length>idx) {
//        printf("Last index at %d: %d\n", idx, data[length-idx]);
//        return 1;
//    } else {
//        return 0;
//    }
    // 这种解法的空间复杂度过高，只能得10分。下面是参考答案
    // 设置两个指针。指针1先行遍历，等到指针1遍历到第idx个节点时指针2开始遍历。
    // 指针1遍历完毕时指针2正指向倒数第idx个节点
    LNode *p1 = l->next, *p2 = l->next;
    int ptr = 0;
    while (p1) {
        if (ptr >= idx) {
            p1 = p1->next;
            p2 = p2->next;
        } else {
            p1 = p1->next;
        }
        ptr++;
    }
    if (ptr >= idx - 1) {
        printf("Last index at %d: %d\n", idx, p2->data);
        return 1;
    } else {
        return 0;
    }
}

// 23 2012统考真题
// 对于loading和being两个词，他们具有相同的后缀ing，如果使用单链表保存这两个单词，相同后缀可以共用。
// 编写一个算法，查找相同后缀的开始节点，要求时间上尽可能高效
LNode *FindCommonSuffix(LinkList A, LinkList B) {
    // 解题思路：长表的指针先遍历长表长度减短表长度次，然后同步遍历两个链表，对剩下部分进行匹配
    //   这道题还有另一种思路。题目要求尽可能时间上高效，那么先把两表的数据复制到两个数组中，然后
    //   进行反向遍历，第一次失配位置的上一个位置就是题目要求的节点
    // 注：参考答案在同步遍历中查找到地址相同的节点即为返回值，但考虑到共用部分节点的两个链表构造起来
    //   比较麻烦，因此这个解法以值为标准查找共同后缀
    int la = LinkListLength(A), lb = LinkListLength(B), idx = 0;
    LNode *pA = A->next, *pB = B->next, *fA, *fB;
    if (la > lb) {
        while (idx != la - lb) {
            pA = pA->next;
            idx++;
        }
    } else {
        while (idx != lb - la) {
            pB = pB->next;
            idx++;
        }
    }
    fA = pA;
    fB = pB;
    while (pA && pB) {
        if (pA->data == pB->data) { // 参考答案在这里的判断条件是pA == pB，然后将其返回
            pA = pA->next;
            pB = pB->next;
        } else {
            fA = fA->next;
            fB = fB->next;
            pA = fA;
            pB = fB;
        }
    }
    if (pA == NULL && pB == NULL) {
        return fA;
    } else {
        return NULL;
    }
}

// 24 2015统考真题
// 使用单链表保存m个整数，将该单链表中节点值绝对值相等的节点移除，只保留第一次出现的节点
void DeduplicateWithAbs(LinkList l, unsigned m) {
    int flag[m];
    // 分配数组空间并置0
    memset(flag, 0, m * sizeof(int));
    LNode *p = l->next;
    while (p) {
        if (flag[abs(p->data)] == 0) {
            // 以数值绝对值作为下标，如果下标所在值为0，说明该元素第一次访问，并置1以表示已访问
            flag[abs(p->data)] = 1;
        } else {
            // 不等于0时，将该节点移除并释放内存空间
            LNode *next = p->next;
            if (!next) {
                p = NULL;
            } else {
                p->data = next->data;
                p->next = next->next;
                free(next);
            }
        }
        p = p->next;
    }
}

// 25 2019统考真题
// 给定单链表，内容为a1, a2, a3, ..., an，将该链表重排成a1, an, a2, an-1, ...，
// 要求空间复杂度为O(1)，且时间上尽可能高效
void LinkListRearrange(LinkList l) {
    int length = LinkListLength(l);
    // 先将后半元素就地逆置，然后将后半部分元素以此插入前半部分
    // 快慢指针同步遍历。快指针每次走两步，慢指针每次走一步。当快指针到达链表末端时，慢指针
    // 位于链表中部
    LNode *fast = l, *slow = l, *next, *mid;
    while (fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    mid = slow;
    // 以尾节点作为头节点，将后半链表进行头插法建表。front表示中间节点的前一个节点，也就
    // 是前半部分链表的尾节点
    next = slow->next;
    slow->next = fast;
    slow = next;
    while (slow!=fast) {
        next = slow->next;
        slow->next = fast->next;
        fast->next = slow;
        slow = next;
    }
    // 这个时候，fast是中部元素的开始，mid是前半列表的尾节点。
    slow = l->next;
    while (fast) {
        next = fast->next;
        mid->next = fast->next;
        fast->next = slow->next;
        slow->next = fast;
        slow = fast->next;
        fast = next;
    }
}

// 枯了。真题一年比一年难了😥
