#include "SqList.h"
#include "stdio.h"

int main()
{
    // Initialization
    SqList list, list2;
    SqListInit(&list, 10);
    SqListInit(&list2, 10);
    ElemType data1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    ElemType data2[] = {1, 2, 4, 5, 7, 8, 9, 10, 11, 12};
    SqListFromArray(&list, data1, 10);
    SqListFromArray(&list2, data2, 10);

    // Operations
    SwapOrInsert(&list, 5);

    // Output
    SqListPrint(&list);
    return 0;
}