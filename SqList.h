#include "commons.h"
#define SQLIST_MAX_SIZE 50
#define ElemType int

typedef struct {
    ElemType* data;
    int length;
} SqList;

Boolean SqListInit(SqList *list, int size);

Boolean SqListInsert(SqList *list, int idx, ElemType elem);

Boolean SqListDelete(SqList *list, int idx);

int SqListLocate(SqList *list, ElemType elem);

void SqListPrint(SqList *list);

void SqListFromArray(SqList *list, ElemType *data, int length);

Boolean DeleteMinElem(SqList *list, ElemType *res);

void SqListReverse(SqList *list, int start, int end);

void DeleteByX(SqList *list, ElemType x);

void DeleteByRange(SqList *list, int s, int t);
