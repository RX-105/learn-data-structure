#ifndef LEARN_DATA_STRUCTURE_CHAPTER8_SORTINGALGORITHMS_H_
#define LEARN_DATA_STRUCTURE_CHAPTER8_SORTINGALGORITHMS_H_

typedef struct {
  int data[10];
  int key;
} redtype;

void swap(int *base, int offset_start, int offset_end);
void BinaryInsertionSort(int *A, int n);
void InsertionSort(int *A, int n);
void BubbleSort(int A[], int n);
void QuickSort(int *A, int low, int high);
void ShellSort(int A[], int n);
void SelectSort(int A[], int n);
void HeapSort(int A[], int len);
void mergesort(redtype r[], int n);

#endif //LEARN_DATA_STRUCTURE_CHAPTER8_SORTINGALGORITHMS_H_
