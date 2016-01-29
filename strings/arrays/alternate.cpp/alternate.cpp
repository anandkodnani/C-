/*
arr[] = {1, 2, 3, -4, -1, 4}
 */

#include <iostream>
#include <algorithm>
using namespace std;

void swapNegative(int *arr, int n) {
  int start = 0;
  for (int i = 0; i < n; ++i) {
    if (arr[i] < 0) {
      swap(arr[start], arr[i]);
      ++start;
    }
  }
}

int main() {
  int arr[] = {1, 2, 3, -4, -1, 4};
  int n = sizeof(arr) / sizeof(n);
  // Put all the negative elements at start.
  swapNegative(arr, n);
  cout << "\n\n";
  for (int i = 0; i < n; ++i)
    cout << "  " << arr[i];
  cout << "\n\n";

  int pos = 0;
  int neg = 1;
  // find the first negative element.
  for (int i = 0; i < n; ++i)
    if (arr[i] >= 0) {
      pos = i;
      break;
    }

  int limit = pos;
  // alternate between negative and positive.
  while (neg < limit && pos < n) {
    swap(arr[neg], arr[pos]);
    neg += 2;
    pos++;
  }

  cout << "\n\n";
  for (int i = 0; i < n; ++i)
    cout << "  " << arr[i];
  cout << "\n\n";

  return 0;
}
