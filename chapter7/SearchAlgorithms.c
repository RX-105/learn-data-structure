int SearchSeq(int A[], int n, int key) {
  for (int i = 0; i < n; i++)
    if (A[i] == key) return i;
  return -1;
}

int BinarySearch(int A[], int n, int key) {
  int low = 0, high = n - 1, mid;
  while (low <= high) {
    mid = (low + high) / 2;
    if (key == A[mid])
      return mid;
    else if (key < A[mid])
      high = low - 1;
    else
      low = mid + 1;
  }
  return -1;
}