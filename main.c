#include "chapter2/SqList.h"
#include "chapter2/LinkList.h"
#include "chapter3/SqStack.h"
#include "chapter4/SString.h"
#include "stdio.h"
#include "string.h"

int main()
{
    // Initialization
    LinkList l = NULL;
    int arr[6] = {6,5,4,3,2,1};
    l = LinkListTailInit(l, 6, arr);

    // Operations
    InsertSort(l);

    // Output
    LinkListPrint(l);

    return 0;
}