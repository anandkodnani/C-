#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

void triplets(int *arr, int n) {
  int a,b,c;
  bool found = false;
  // Square all the elements.
  for (unsigned i = 0; i < n; ++i)
    arr[i] = arr[i] * arr [i];

  // Sort the array.
  sort(arr, arr + n, std::less<int>());

  for (unsigned i = 0; i < n; ++i) {
    int x = -arr[i];
    int p = i;
    int start = 0, end = n - 1;
    while (start < end) {
      if (start == p) {
        ++start;
        continue;
      }

      if (end == p) {
        --end;
        continue;
      }
      if (x + arr[start] + arr[end] == 0) {
        a = -x; b = arr[start]; c = arr[end];
        found =  true;
        break;
      } else if (x + arr[start] + arr[end] > 0)
        --end;
      else if (x + arr[start] + arr[end] < 0)
        ++start;
    }
    if (found) 
      break;
  }

  if (found) {
    cout << "\n\n" << sqrt(a) << "  " << sqrt(b) << " "
         << sqrt(c);
    cout << "\n\n";
  } else
    cout << "\n\ntriplets not found\n\n";
}

int main() {
  int arr[] = {3, 1, 4, 6, 5};
  int n = sizeof(arr) / sizeof(arr[0]);
  triplets(arr, n);
  return 0;
}
