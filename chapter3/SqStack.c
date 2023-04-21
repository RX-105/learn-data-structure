#include "SqStack.h"
#include "stdlib.h"

void InitStack(SqStack *st)
{
    st->top = -1;
}
int StackEmpty(SqStack *st)
{
    return st->top == 0;
}
int Push(SqStack *st, int x)
{
    if (st->top == MAXSIZE - 1)
    {
        return -1;
    }
    st->data[++st->top] = x;
    return 1;
}
int Pop(SqStack *st, int *x)
{
    if (st->top == -1)
        return 0;
    *x = st->data[st->top--];
    return 1;
}
int GetTop(SqStack *st, int *x)
{
    if (st->top == -1)
        return 0;
    *x = st->data[st->top];
    return 1;
}
int PatternTest(char *seq, int len)
{
    int top = -1;
    for (int i = 0; i < len; i++)
    {
        switch (seq[i])
        {
        case 'I':
            top++;
            break;

        case 'O':
            if (top == -1)
                return 0;
            else
                top--;
            break;
        
        default:
            break;
        }
    }
    return 1;
}
// int IsSymmetric(LinkList list, int n)
// {
//     SqStack st;
//     InitStack(&st);
//     LNode *node = list->next;
//     int i;
//     for (i = 0; i < n/2; i++)
//     {
//         Push(&st, node->data);
//         node = node->next;
//     }
//     if (n%2 == 1)
//     {
//         i++;
//         node = node->next;
//     }
//     for (int i = 0; i < n; i++)
//     {
//         char tmp;
//         Pop(&st, &tmp);
//         if (tmp == node->data)
//             node = node->next;
//         else
//             return 0;
//     }
//     return 1;
// }
