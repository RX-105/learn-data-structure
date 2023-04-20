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
    StrAssign(&master, "ababcabcacbab", 13);
    StrAssign(&pattern, "abcac", 5);

    // Operations
    printf("Index at: %d\n", Index(&master, &pattern));

    // Output
    return 0;
}