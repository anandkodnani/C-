/*
  Input:  arr[]   = [10, 11, 12];
  index[] = [1, 0, 2];

*/
#include <iostream>
#include <algorithm>
using namespace std;

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
void reorder(int *arr, int *index, int size) {
  
  for (unsigned i = 0; i < size; ++i) {
    int p = index[i];
    while (p != i) {
      swap(&arr[i], &arr[p]);
      swap(&index[i], &index[p]);
      p = index[i];
    }
  }
}

int main() {
  //int arr[]   = {10, 11, 12};
  //int index[] = {1, 0, 2};
  int arr[] = {50, 40, 70, 60, 90};
  int index[] = {3,  0,  4,  1,  2};
  int size = sizeof(index) / sizeof(index[0]);
  reorder(arr, index, size);
  cout << "\n\n";
  for (unsigned i = 0; i < size; ++i)
    cout << "  " << arr[i];
  cout << "\n";
  return 0;
}
