#define MAXSIZE 50

typedef struct {
    int data[MAXSIZE];
    int top;
} SqStack;

void InitStack(SqStack *st);
int StackEmpty(SqStack *st);
int Push(SqStack *st, int x);
int Pop(SqStack *st, int *x);
int GetTop(SqStack *st, int *x);
