/*
2 
4 
1 2 3 4
6
2 -1 2 3 4 -5
 */

#include <iostream>
#include <fstream>
using namespace std;

int kadane_cont(int arr[], int N) {
  // 1. If it has postive and negative elements.
   bool allNegative = true;
  int maxElement = arr[0];
  for (int i = 0; i < N; ++i) {
    if (arr[i] > maxElement)
      maxElement = arr[i];

    if (arr[i] > 0) {
      allNegative = false;
    }
  }
 
  if (allNegative)
  return maxElement;

  int curr_sum = 0;
  int best_sum = 0;
  for (int i = 0; i < N; ++i) {
    curr_sum += arr[i];
    if (curr_sum < 0) {
      curr_sum = 0;
    }
    
    if (curr_sum > best_sum)
      best_sum = curr_sum;
  }
  return best_sum;
}

int kadane_non_cont(int arr[], int N) {
  // 1. If it has postive and negative elements.
  bool allNegative = true;
  int maxElement = arr[0];
  for (int i = 0; i < N; ++i) {
    if (arr[i] > maxElement)
      maxElement = arr[i];

    if (arr[i] > 0) {
      allNegative = false;
    }
  }
 
  if (allNegative)
    return maxElement;

  int curr_sum = 0;
  for (int i = 0; i < N; ++i) {
    if (arr[i] > 0)
      curr_sum += arr[i];
  }
  return curr_sum;

}

int main() {
  ifstream in("input.txt");
  int numTestCase;
  in >> numTestCase;

  for (int i = 0; i < numTestCase; ++i) {
    int N;
    in >> N;
    int arr[N];
    for (int j = 0; j < N; ++j)
      in >> arr[j];

    cout << kadane_cont(arr, N) << " "
         << kadane_non_cont(arr, N) << "\n";
  }
  return 0;
}
