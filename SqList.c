#include "SqList.h"
#include "commons.h"
#include "stdlib.h"
#include "stdio.h"

/// @brief 初始化一个顺序表，size参数必须是一个合法参数（不为负数，小于SQLIST_MAX_SIZE）
/// @param list 顺序表对象
/// @param size 列表初始大小
/// @return 以true表示成功初始化，以false表示size参数不合法
Boolean SqListInit(SqList *list, int size)
{
    if (size < 0 || size > SQLIST_MAX_SIZE)
    {
        return BOOLEAN_FALSE;
    }
    list->data = (ElemType *)malloc(sizeof(ElemType) * SQLIST_MAX_SIZE);
    list->length = size;
    for (ElemType i = 0; i < list->length; i++)
    {
        list->data[i] = i;
    }
    return BOOLEAN_TRUE;
}

/// @brief 在顺序表中指定下标的位置插入一个元素
/// @param list 顺序表对象
/// @param idx 插入位置的下标
/// @param elem 插入的元素
/// @return 以true表示成功插入，以false表示idx参数不合法
Boolean SqListInsert(SqList *list, int idx, ElemType elem)
{
    // 检查idx的取值是否合法
    if (idx < 0 || idx > list->length)
    {
        return BOOLEAN_FALSE;
    }
    // 检查列表大小是否超出最大大小
    if (list->length + 1 > SQLIST_MAX_SIZE)
    {
        return BOOLEAN_FALSE;
    }
    // 从后往前移一个元素
    for (int i = list->length + 1; i > idx; i--)
    {
        list->data[i] = list->data[i - 1];
    }
    list->data[idx] = elem;
    list->length++;
    return BOOLEAN_TRUE;
}

/// @brief 在顺序表中指定下标的位置删除一个元素
/// @param list 顺序表对象
/// @param idx 删除元素位置的下标
/// @return 以true表示成功删除，以false表示idx参数不合法
Boolean SqListDelete(SqList *list, int idx)
{
    if (idx < 0 || idx > list->length)
    {
        return BOOLEAN_FALSE;
    }
    for (int i = idx; i < list->length; i++)
    {
        list->data[i] = list->data[i + 1];
    }
    list->length--;
    return BOOLEAN_TRUE;
}

/// @brief 在顺序表中查找指定元素首次出现的位置
/// @param list 顺序表对象
/// @param elem 需要查找的元素
/// @return 该元素首次出现位置的下标
int SqListLocate(SqList *list, ElemType elem)
{
    for (int i = 0; i < list->length; i++)
    {
        if (list->data[i] == elem)
        {
            return i;
        }
    }
    return -1;
}

/// @brief 将列表元素打印到标准输出上
/// @param list 顺序表对象
void SqListPrint(SqList *list)
{
    printf("SqList: [");
    for (int i = 0; i < list->length; i++)
    {
        printf("%d ", list->data[i]);
    }
    printf("\b]\n");
}

/// @brief 以数组作为顺序表的数据
/// @param list 顺序表对象
/// @param data 数组数据
/// @param length 数组数据的长度
void SqListFromArray(SqList *list, ElemType *data, int length)
{
    for (int i = 0; i < list->length && i < length; i++)
    {
        list->data[i] = data[i];
    }
}

// 题目算法

// 2.2.3 二.01
Boolean DeleteMinElem(SqList *list, ElemType *res)
{
    if (list->length == 0)
    {
        return BOOLEAN_FALSE;
    }
    ElemType e = list->data[0];
    int idx = 0;
    for (int i = 1; i < list->length; i++)
    {
        if (list->data[i] < e)
        {
            e = list->data[i];
            idx = i;
        }
    }
    list->data[idx] = list->data[list->length - 1];
    list->length--;
    return BOOLEAN_TRUE;
}

// 2.2.3 二.02
void SqListReverse(SqList *list, int start, int end)
{
    if (start < 0 || end > list->length)
    {
        return;
    }
    int mid = (end - start) / 2;
    for (int i = 0; i < mid; i++)
    {
        ElemType temp = list->data[start + i];
        list->data[start + i] = list->data[end - i];
        list->data[end - i] = temp;
    }
}

// 2.2.3 二.03
void DeleteByX(SqList *list, ElemType x)
{
    int pos = 0;
    for (int i = 0; i < list->length; i++)
    {
        if (list->data[i] != x)
        {
            list->data[pos++] = list->data[i];
        }
    }
    list->length = pos;
}

// 2.2.3 二.04
void DeleteByRange(SqList *list, int s, int t)
{
    int i, j;
    if (s < 0 || t > list->length + 1 || s > t)
    {
        return;
    }
    for (i = 0; i < list->length && list->data[i] < s; i++)
        ;
    for (j = i; j < list->length && list->data[j] <= t; j++)
        ;
    for (; j < list->length; i++, j++)
    {
        list->data[i] = list->data[j];
    }
    list->length = i;
}
