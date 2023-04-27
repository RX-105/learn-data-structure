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
    int arr2[3] = {4,5,6};
    l = LinkListTailInit(l, 6, arr);
    l2 = LinkListTailInit(l2, 3, arr2);

    // Operations
    LinkListRearrange(l);

    // Output
    LinkListPrint(l);

    return 0;
}