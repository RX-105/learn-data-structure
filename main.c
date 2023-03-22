#include "SqList.h"
#include "stdio.h"

int main()
{
    SqList list;
    SqListInit(&list, 10);
    ElemType data[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    SqListFromArray(&list, data, 10);
    DeleteByRange(&list, 3, 6);
    SqListPrint(&list);
    return 0;
}