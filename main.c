#include "chapter2/SqList.h"
#include "chapter2/LinkList.h"
#include "chapter3/SqStack.h"
#include "chapter4/SString.h"
#include "stdio.h"

#define QUEUE_SIZE 100
typedef struct {
    int data[QUEUE_SIZE];
    int rear, front;
} SqQueue;

int EnQueue(SqQueue *q, int x) {
    if(q->rear == QUEUE_SIZE) return -1;
    q->data[q->rear] = x;
    q->rear++;
    return 0;
}

int DeQueue(SqQueue *q, int *x) {
    if (q->front == q->rear) return -1;
    *x = q->data[q->front];
    return 0;
}

int main() {
    // Initialization
    LinkList l = NULL;
    LinkList l2 = NULL;
    int arr[6] = {1,2,3,4,5,6};
    int arr2[3] = {4,5,6};
    SqList l3;
    SqListInit(&l3, 7);
    SqListFromArray(&l3, arr, 6);

    // Operations
//    LinkListRearrange(l);

    // Output
//    LinkListPrint(l);

    return 0;
}