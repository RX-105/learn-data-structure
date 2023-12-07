
#include <stdlib.h>

#include "stdio.h"
#include "SortingAlgorithms.h"

void swap(int *base, int offset_start, int offset_end) {
  int tmp = *(base + offset_start);
  *(base + offset_start) = *(base + offset_end);
  *(base + offset_end) = tmp;
}

// void InsertionSort(int *num, int length) {
//     int cur, i, j;
//     for (i = 1; i < length; i++) {
//         cur = num[i];  // 待排序元素
//         for (j = i - 1; j >= 0 && num[j] > cur; j--) {
//             num[j + 1] = num[j];
//         }
//         num[j + 1] = cur;
//     }
// }

void BinaryInsertionSort(int *A, int n) {
  int i, j, low, mid, high;
  for (i = 2; i < n; i++) {
    A[0] = A[i];
    low = 1;
    high = i - 1;
    while (low < high) {
      mid = (low + high) / 2;
      if (A[0] < A[mid])
        high = mid - 1;
      else
        low = mid + 1;
    }
    for (j = i - 1; j >= high + 1; --j) {
      A[j + 1] = A[j];
    }
    A[j + 1] = A[0];
  }
}

void InsertionSort(int *A, int n) {
  int i, j;
  for (i = 2; i < n; ++i) {   // 下标0作为哨兵时，从2开始搜索
    if (A[i] < A[i - 1]) {  // 本元素比前元素还小，需要排序
      A[0] = A[i];        // 设置哨兵
      // 从后往前依次后移，直到找到插入位置
      for (j = i - 1; A[0] < A[j]; j--) {
        A[j + 1] = A[j];
      }
      A[j + 1] = A[0];  // 哨兵回位
    }
  }
}

void BubbleSort(int A[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int flag = 0;  // 标志本次排序是否发生交换
    for (int j = n - 1; j > 1; j--) {
      if (A[j - 1] > A[j]) {
        swap(A, j - 1, j);
        flag = 1;
      }
    }
    if (flag == 0) return;
  }
}

int Partition(int *A, int low, int high) {
  int pivot = A[low];
  while (low < high) {
    // 从右侧开始寻找小于pivot的下标（右边留大）
    while (low < high && A[high] >= pivot) high--;
    A[low] = A[high];
    // 从左侧开始寻找大于pivot的下标（左边留小）
    while (low < high && A[low] <= pivot) low++;
    A[high] = A[low];
  }
  A[low] = pivot;
  return low;
}

void QuickSort(int *A, int low, int high) {
  if (low < high) {
    int pPos = Partition(A, low, high);
    QuickSort(A, low, pPos - 1);
    QuickSort(A, pPos + 1, high);
  }
}

void ShellSort(int A[], int n) {
  int dk, i, j;
  for (dk = n / 2; dk >= 1; dk /= 2) {
    for (i = dk + 1; i <= n; i++) {
      if (A[i] < A[i - dk]) {
        A[0] = A[i];
        for (j = i - dk; j > 0 && A[0] < A[j]; j -= dk) {
          A[j + dk] = A[j];
        }
        A[j + dk] = A[0];
      }
    }
  }
}

void SelectSort(int A[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int min = i;
    for (int j = i + 1; j < n; j++) {
      if (A[j] < A[min]) min = j;
    }
    if (min != i) swap(A, min, i);
  }
}

void HeadAdjust(int A[], int k, int len) {
  A[0] = A[k];
  // k是根的位置，k*2就对应了k的叶结点
  for (int i = 2 * k; i <= len; i *= 2) {
    // 从叶结点中选取更大的那个
    if (i < len && A[i] < A[i + 1]) i++;
    // 父结点比子结点都大，不需要交换
    if (A[0] > A[i])
      break;
    else {
      A[k] = A[i];
      k = 1;
    }
  }
  A[k] = A[0];
}
void BuildMaxHeap(int A[], int len) {
  for (int i = len / 2; i > 0; i--) {
    HeadAdjust(A, i, len);
  }
}
void HeapSort(int A[], int len) {
  BuildMaxHeap(A, len);
  for (int i = len; i > 1; i--) {
    swap(A, i, 1);
    HeadAdjust(A, 1, i - 1);
  }
}

// 来自卢玲版数据结构
void merge(redtype r[], int low, int m, int high) {
  int i = low, j = m + 1, p = 0;
  redtype *t;
  t = (redtype *) malloc(sizeof(redtype) * (high - low + 1));
  while (i <= m && j <= high)
    t[p++] = r[i].key < r[j].key ? r[i++] : r[j++];
  while (i <= m)
    t[p++] = r[i++];
  while (j < high)
    t[p++] = r[j++];
  for (p = 0, i = low; i < high; i++, p++)
    r[i] = t[p];
}

void mergepass(redtype r[], int n, int length) {
  int i;
  for (i = 0; i + 2 * length - 1 < n; i += 2 * length)
    merge(r, i, i + length - 1, i + 2 * length - 1);
  if (i + length - 1 < n - 1)
    merge(r, i, i + length - 1, n - 1);
}

void mergesort(redtype r[], int n) {
  int length;
  for (length = 1; length < n; length *= 2)
    mergepass(r, n, length);
}

int main(int argc, char const *argv[]) {
  int A[6] = {0, 3, 1, 2, 5, 4};
  QuickSort(A, 1, 5);
  // InsertSort(A, 6);
  swap(A, 1, 5);
  for (int i = 1; i < 6; i++) {
    printf("%d\n", A[i]);
  }
  return 0;
}
