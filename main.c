#include "SqList.h"
#include "LinkList.h"
#include "stdio.h"

int main()
{
    // Initialization
    LinkList list;
    list = LinkListHeadInit(list, 10);

    // Operations

    // Output
    LinkListPrint(list);
    return 0;
}