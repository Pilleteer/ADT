#include <stdio.h>
#include <stdlib.h>
#define nSize 100000
void swap(int *arr, int m, int n) {
  int temp = arr[m];
  arr[m] = arr[n];
  arr[n] = temp;
}
void printarr(int *arr, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}
void insert(int *arr, int pos) {
  int i = pos;
  while (i >= 1 && arr[i] < arr[i - 1]) {
    swap(arr, i, i - 1);
    i -= 1;
  }
  if (arr[pos] < arr[pos - 1]) {
    insert(arr, pos);
  }
}
void insert_sort(int *arr, int n) {
  for (int i = 0; i < n - 1; i++) {
    if (arr[i + 1] < arr[i]) {
      insert(arr, i + 1);
    }
    printarr(arr, n);
  }
}
void main() {
  int i, n;
  int *arr = (int *)malloc(sizeof(int) * nSize);
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  insert_sort(arr, n);
}
/*
8
4 3 2 10 12 1 5 6

9
54 26 93 17 77 31 44 55 20

16
9 15 8 1 4 11 7 12 13 6 5 3 16 2 10 14
*/