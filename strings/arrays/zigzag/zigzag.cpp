/*
arr[] = {4, 3, 7, 8, 6, 2, 1}

1. 4 3 7
if (arr[i] > arr[i + 1])
swap
3 4 7
if (arr[i + 1] > arr[i + 2])
swap
3 7 4
order = less;
 7 4 8

less =  1;
greater = 0; 
*/

#include <iostream>
using namespace std;

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void checkSwap (int *arr, int i, bool order) {
  if (order) {
    if (arr[i] > arr[i - 1])
      swap(&arr[i], &arr[i - 1]);
    if (arr[i] > arr[i + 1])
      swap(&arr[i + 1], &arr[i + 1]);
  }

  if (arr[i] < arr[i - 1])
    swap(&arr[i], &arr[i - 1]);
  if (arr[i] < arr[i + 1])
    swap(&arr[i], &arr[i + 1]);
}

void reorder(int *arr, int n) {
  bool order = false;
  for (unsigned i = 1; i < n - 1; i += 2) {
    checkSwap(arr, i, order);
    cout << "\n\n";
    for (unsigned i = 0; i < n; ++i)
      cout << "   " << arr[i];
    cout << "\n\n";
    order = ~order;
  }
}

int main() {
  int   arr[] = {4, 3, 7, 8, 6, 2, 1};
  int n = sizeof(arr) / sizeof(arr[0]);
  reorder(arr, n);

  cout << "\n\nFinal array:    ";
  for (unsigned i = 0; i < n; ++i)
    cout << "   " << arr[i];
  cout << "\n\n";
  return 0;
}
