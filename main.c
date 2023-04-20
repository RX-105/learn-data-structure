#include "chapter2/SqList.h"
#include "chapter2/LinkList.h"
#include "chapter4/SString.h"
#include "stdio.h"
#include "string.h"

int main()
{
    // Initialization
    SString master;
    SString pattern;
    StrAssign(&master, "abaabcaba", 9);
    StrAssign(&pattern, "abcab", 5);
    int next[9] = {0};

    // Operations
    // GetNext(&master, next);

    // Output
    printf("Index at: %d\n", Index(&master, &pattern));
    printf("(KMP)Index at: %d\n", Index_KMP(&master, &pattern, next));
    return 0;
}