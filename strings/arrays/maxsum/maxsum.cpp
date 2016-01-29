/*
arr[] = {1, 20, 2, 10}

1. find the sum of original array.
0*1 + 1*20 + 2*2 + 3*10 = 54
sum of whole array = 33

2. right rotate once = 54 + 33 - 30 = 57
0*10 + 1*1 + 2*20 + 3*2 = 47

3, right rotate twice:
0*2 + 1*10 + 2*1 + 3*20 =  72

4. right rotate thrice:
0*20 + 1*2 + 2*10 + 3*1 = 25 =  72 + 33 - 4*20 = 25

5. right rotate four times:
0*1 + 1*20 + 2*2 + 3*10 = 54
eqn:  sum_array + original_sum - 4*previous_last_element.
*/

#include <iostream>
using namespace std;

int max_sum(int *arr, int size) {

  int sum_array = 0;
  for (unsigned i = 0; i < size; ++i) {
    sum_array += arr[i];
  }

  int orig_sum = 0;
  for (unsigned i = 0; i < size; ++i)
    orig_sum += arr[i]*i;

  int max_sum = orig_sum;
  int new_sum = orig_sum;
  // start the rotations.
  for (int i = size - 1; i >= 0; --i) {
    new_sum = orig_sum + sum_array - size*arr[i];
    cout << "\n\n" << new_sum;
    if (max_sum < new_sum)
      max_sum = new_sum;
    orig_sum = new_sum;
  }
  return max_sum;
}

int main() {
  int arr[] = {10, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int size =  sizeof(arr) / sizeof(arr[0]);
  cout << "\n\n" << max_sum(arr, size) << "\n\n";
  return 0;
}
