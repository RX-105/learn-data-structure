#include "SqList.h"
#include "../commons.h"
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

/// @brief 将数组数据中前length个数据复制到线性表内
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

void SqListDestroy(SqList *list)
{
    free(list->data);
}

// 题目算法

// 2.2.3 二.01
// 删除具有最小值的元素，空余位置由最后一个元素填充
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
// 设计一个高效算法，逆置所有元素，空间复杂度为O(1)
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
// 删除元素值等于x的元素，时间复杂度为O(n)，空间复杂度为O(1)
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
// 删除顺序表中s到t范围内（包括）的数据
// 已知SqList数据有序
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

// 2.2.3 二.05
// 删除顺序表中s到t范围内（包括）的数据
// 不能确定SqList数据有序
void DeleteByRange2(SqList *list, int s, int t)
{
    if (s < 0 || t > list->length - 1 || s > t)
    {
        return;
    }
    int pos = 0;
    for (int idx = 0; idx < list->length; idx++)
    {
        if (!(list->data[idx] >= s && list->data[idx] <= t))
        {
            list->data[pos++] = list->data[idx];
        }
    }
    list->length = pos;
}

// 2.2.3 二.06
// 在有序顺序表中删除多于元素
// 已知SqList数据有序
void DeleteDuplicates(SqList *list)
{
    // 0 1 2 2 3 3 3 4 5
    // 先用pos指向元素0，idx从1开始。检查元素0和元素1是否相同，如果不同，就把pos加一，
    // 然后把idx位置元素复制到pos位置上，如果相同，就把idx后移，但pos不动
    // 本质上和上一道题类似，在同一个列表上重新写入数据，记录一个新的length
    int pos, idx; // 使用pos表示新数组的位置，idx作为循环遍历
    for (pos = 0, idx = 1; idx < list->length; idx++)
    {
        if (list->data[pos] != list->data[idx])
        {
            list->data[++pos] = list->data[idx];
        }
    }
    list->length = pos + 1;
}

// 2.2.3 二.07
// 将两个有序顺序表合并
void SqListMerge(SqList *list1, SqList *list2, SqList *list)
{
    int length = 0, length1 = 0, length2 = 0;
    while (length1 < list1->length && length2 < list2->length)
    {
        if (list1->data[length1] < list2->data[length2])
            list->data[length++] = list1->data[length1++];
        else
            list->data[length++] = list2->data[length2++];
    }
    while (length1 < list1->length)
        list->data[length++] = list1->data[length1++];
    while (length2 < list2->length)
        list->data[length++] = list2->data[length2++];
    list->length = length;
}

// 2.2.3 二.08
// 给定数组A[m+n]={A1, ..., Am, B1, ..., Bn}，将前m项和后n项整体交换位置
void ArraySwap(SqList *A, int m, int n)
{
    SqListReverse(A, 0, m + n - 1);
    SqListReverse(A, 0, n - 1);
    SqListReverse(A, n, m + n - 1);
}

// 2.2.3 二.09
// 用最少的时间查找x。元素不存在时，插入并使列表仍然有序；存在元素时，将其与后一个元素交换
void SwapOrInsert(SqList *list, ElemType x)
{
    // 使用二分法搜索
    int idx = -1;
    int low = 0, high = list->length - 1, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (x == list->data[mid])
            break;
        else if (x < list->data[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    if (x != list->data[mid])
    {
        // 元素不存在时，插入并使列表仍然有序
        int i = list->length;
        for (; i > 0 && list->data[i - 1] > x; i--)
            list->data[i] = list->data[i - 1];
        list->data[i] = x;
        list->length++;
    }
    else
    {
        // 存在元素时，将其与后一个元素交换
        idx = mid;
        ElemType temp = list->data[idx];
        list->data[idx] = list->data[idx + 1];
        list->data[idx + 1] = temp;
    }
}

// 2.2.3 二.10 [2010年统考真题]
// 参考二.08

// 2.2.3 二.11 [2011年统考真题]
// 在两个等长的升序数组中寻找合并后的中位数（即array[length/2]），要求尽可能时间空间都高效
ElemType FindIntermediate(int *arr1, int *arr2, int length)
{
    int l1 = 0, l2 = 0, h1 = length - 1, h2 = length - 1;
    int m1, m2;
    // 这个条件表示双方数组都只剩下一个元素，不满足条件之后就在两个数之间取更大的数即为结果
    while (h1 - l1 != 0 && h2 - l2 != 0)
    {
        // 表示当前中位数下标
        m1 = (h1 - l1 + 1) / 2;
        m2 = (h2 - l2 + 1) / 2;
        // 判断当前中位数大小
        if (arr1[l1 + m1] < arr2[l2 + m2])
        {
            // 如果a1比a2小，取a1的后半、a2的前半
            l1 += m1;
            h2 -= m2;
        }
        else
        {
            // 如果a1比a2大，取a1的前半、a2的后半
            h1 -= m1;
            l2 += m2;
        }
    }
    return arr1[l1] > arr2[l2] ? arr1[l1] : arr2[l2];
}

// 2.2.3 二.12 [2013年统考真题]
// 在一个升序数组中寻找众数，且数量大于length/2，没有则返回-1
ElemType FindMostOccurence(int *arr, int length)
{
    // 默认元素为第一个，计数器置为1
    ElemType elem = arr[0];
    int cnt = 1, idx = 1;
    while (idx < length)
    {
        // 对于相同元素，计数器加一，否则减一
        if (arr[idx] == elem)
            cnt++;
        else
            cnt--;
        // 如果计数器小于0，则把当前元素保存下来，重置计数器
        if (cnt < 0)
        {
            elem = arr[idx];
            cnt = 1;
        }
        idx++;
    }
    // 重新统计元素的真正出现次数
    cnt = 0;
    for (idx = 0; idx < length; idx++)
    {
        if (arr[idx] == elem)
            cnt++;
    }
    return cnt > length / 2 ? elem : -1;
}

// 2.2.3 二.13 [2018年统考真题]
// 在一个数组中寻找没出现过的最小正整数，要求时间上尽可能高效
ElemType FindMinInt(int *arr, int length)
{
    int occurence[__INT16_MAX__] = {0};
    for (int idx = 0; idx < length; idx++)
    {
        if (arr[idx] >= 0)
            occurence[arr[idx]]++;
    }
    for (int idx = 1; idx < __INT16_MAX__; idx++)
    {
        if (occurence[idx] == 0)
            return idx;
    }
}
