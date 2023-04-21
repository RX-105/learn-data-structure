#include "chapter2/SqList.h"
#include "chapter2/LinkList.h"
#include "chapter3/SqStack.h"
#include "chapter4/SString.h"
#include "stdio.h"
#include "string.h"

int main()
{
    // Initialization
    SqStack st;
    InitStack(&st);

    // Operations
    Push(&st, 1);
    Push(&st, 2);
    Push(&st, 3);
    Push(&st, 4);

    // Output
    int tmp;
    Pop(&st, &tmp);
    printf("Pop: %d\n", tmp);
    Pop(&st, &tmp);
    printf("Pop: %d\n", tmp);
    Pop(&st, &tmp);
    printf("Pop: %d\n", tmp);
    Pop(&st, &tmp);
    printf("Pop: %d\n", tmp);

    return 0;
}