#include "SqStack.h"

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