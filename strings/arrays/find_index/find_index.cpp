/*
arr[] =  {1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1}

Find the position of 0 which gives longest sequence of 1.

1. replace 1st 0 with 1; store the max sequence of 1s before it
and the position which was flipped.

2. on the next 0 calculate 
 */
#include <iostream>
using namespace std;

int find_max(int *arr, int n) {
  int max_seq = 0;
  int curr_seq = 0;
  int max_pos = 0;
  int curr_pos = 0;

  for (int i = 0; i < n; ++i) {
    if (arr[i] == 1) {
      curr_seq++;
      continue;
    }

    // Handle when you hit 0
    if (i == 0 || arr[i - 1] == 0) {
      curr_seq = 0;
      curr_pos =0;
      continue;
    }

    if (arr[i - 1] == 1) {
      curr_pos = i;
      curr_seq++;
      if (curr_seq > max_seq) {
        max_seq = curr_seq;
        max_pos = curr_pos;
      }
    }
  }
  return max_pos;
}

int main() {
  int arr[] =  {1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1};
  int n =  sizeof(arr) / sizeof(n);
  cout << "\n\nThe position is " << find_max(arr, n) << "\n\n";
  return 0;
}
