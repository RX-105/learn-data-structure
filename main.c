#include "SqList.h"
#include "stdio.h"

int main()
{
    // Initialization
    SqList list, list2;
    SqListInit(&list, 10);
    SqListInit(&list2, 10);
    ElemType data1[] = {-5, 3, 2, 3, 4};
    ElemType data2[] = {2, 4, 6, 8, 20};
    SqListFromArray(&list, data1, 10);
    SqListFromArray(&list2, data2, 10);

    // Operations
    printf("%d\n", FindMinInt(data1, 5));

    // Output
    SqListPrint(&list);
    return 0;
}