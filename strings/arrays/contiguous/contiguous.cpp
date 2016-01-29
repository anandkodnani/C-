/*
arr[] = {1, 56, 58, 57, 90, 92, 94, 93, 91, 45};
 1  45  56  57  58  90  91  92  93  94
 */

#include <iostream>
#include <algorithm>
using namespace std;

int largest(int *arr, int n) {
  int max_len = 0;
  int start_pos = 0;
  int curr_len = 1;
  int curr_pos = 0;

  for (int i = 0; i < n - 1; ++i) {
    if (arr[i + 1] - arr[i] == 1) {
      curr_len++;
      continue;
    }

    // When the sequence breaks.

    if (curr_len > max_len) {
      max_len = curr_len;
      start_pos = curr_pos;
    }
    curr_pos = i + 1;
    curr_len = 1;
  }
  if (curr_len > max_len) {
    max_len = curr_len;
    start_pos = curr_pos;
  }
  
  return max_len;
}

int main() {
  int arr[] = {1, 56, 58, 57, 90, 92, 94, 93, 91, 45};
  int n = sizeof(arr) / sizeof(arr[0]);
  sort(arr, arr + n, std::less<int>());
  cout << "\n\n";
  for (int i = 0; i < n; ++i)
    cout << "  " << arr[i];
  cout << "\n\nThe largest subarray is: " << largest(arr, n) << "\n\n";
  return 0;
}
