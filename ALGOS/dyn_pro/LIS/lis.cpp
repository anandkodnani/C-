#include <iostream>
#include <vector>
using namespace std;

void LIS(int *arr, int n) {
  int max = 1;
  int lis[n];
  
  for (unsigned i = 0; i < n; ++i)
    lis[i] = 1;

  for (unsigned i = 1; i < n; ++i)
    for (unsigned j = 0; j < i; ++j)
      if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
        lis[i] = lis[j] + 1;

  for (unsigned i = 0; i < n; ++i)
    if (max < lis[i])
      max = lis[i];

  cout << "\n" << max;
}

int main() {
  int arr[] = {10, 22, 9, 33, 21, 50, 41, 60};
  int n = sizeof(arr) / sizeof(arr[0]);
  LIS(arr, n);
  return 0;
}
