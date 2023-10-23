#include "chapter2/SqList.h"
#include "chapter2/LinkList.h"
#include "chapter3/SqStack.h"
#include "chapter4/SString.h"
#include "stdio.h"

int sqlist_insert(SqList *list, int index, int data){
    int tmp, i = index;
    if (index > list->length){
        return -1;
    }
    else{
        while (i < list->length){
            tmp = list->data[i];
            list->data[i] = data;
            i++;
            data = tmp;
        }
        return 0;
    }
}

int sqlist_delete_first(SqList *list) {
    if (list->length == 0) {
        return -1;
    } else {
        int i = 0;
        while (i < list->length) {
            list->data[i] = list->data[i];
            i++;
        }
        list->length--;
        return 0;
    }
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
    SqListPrint(&l3);
    sqlist_insert(&l3, 1, 10);
    sqlist_delete_first(&l3);
    SqListPrint(&l3);

    // Output
//    LinkListPrint(l);

    return 0;
}