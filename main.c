#include "chapter2/SqList.h"
#include "chapter2/LinkList.h"
#include "chapter3/SqStack.h"
#include "chapter4/SString.h"
#include "stdio.h"
#include "string.h"

int main() {
    // Initialization
    LinkList l = NULL;
    LinkList l2 = NULL;
    int arr[6] = {1,2,3,4,5,6};
    int arr2[6] = {4,5,6,7,8,9};
    l = LinkListTailInit(l, 6, arr);
    l2 = LinkListTailInit(l2, 6, arr2);

    // Operations
    l = GetPublicNodes(l, l2);

    // Output
    LinkListPrint(l);
//    LinkListPrint(l2);

    return 0;
}