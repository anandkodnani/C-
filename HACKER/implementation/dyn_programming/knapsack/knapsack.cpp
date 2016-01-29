/*
2
3 12
1 6 9
5 9
3 4 4 4 8

0-1 case:

max(val + kp[i - 1][]);
recursion:

int knapsack(int arr[], int k, int start, int end) {
 if (start > end)
   return INT_MAX;

  if (k == 0)
    return 0;

  if (k < 0)
    return -k;

  int curr_sum = INT_MAX;
  int div = k / arr[start]
  for (int i = 0; i <= div; ++i)
   curr_sum = 
   min(curr_sum, knapsack(arr, k - i * arr[start], sum, start + 1, end));

   return curr_sum;
}

dyn_prog:

int knapsack(int arr[], int sum, int N) {

  if (sum <= 0)
    return 0;

  int kps[N][sum + 1];
  for (int i = 0; i < N; ++i)
    for (int j = 0; j <= sum; ++j) {
     if (i == 0 || j == 0)
      kps[i][j] = 0;
     else if (arr[i - 1] <= j) {
      int div = j / arr[i - 1];
      int val = INT_MAX;
      for (int k = 0; k <= div; ++k) {
       val = min(val, min(sum - k * arr[i - 1] - kps[i - 1][j - k * i],
       sum - kps[i - 1][j]));
      }
       kps[i][j] = val;
      } else
        kps[i][j] = kps[i - 1][j];
    }
return kps[N - 1][sum];
}
 */

#include <iostream>
#include <fstream>
#include <climits>
using namespace std;

int knapsack(int arr[], int sum, int N) {
  
  int kps[N + 1][sum + 1];
  for (int i = 0; i <= N; ++i)
    for (int j = 0; j <= sum; ++j) {
      if (j == 0 || i == 0)
        kps[i][j] = 0;
       else if (arr[i - 1] <= j) {
        int div = j / arr[i - 1];
        int val = 0;
        for (int k = 0; k <= div; ++k) {
          int prev = val;
          val = max(val, max(k * arr[i - 1] + kps[i - 1][j - k * arr[i - 1]],
                             kps[i - 1][j]));
          if (val > sum)
            val = prev;
        }
        kps[i][j] = val;
      } else
        kps[i][j] = kps[i - 1][j];
    }
  return kps[N][sum];
}

int main() {
  ifstream in("input2.txt");
  int numTestCase;
  in >> numTestCase;
  for (int k = 0; k < numTestCase; ++k) {
    int N, sum;
    in >> N >> sum;
    int arr[N];
    for (int i = 0; i < N; ++i)
      in >> arr[i];
    int val = knapsack(arr, sum, N);
    if (val < 0)
      cout << "0\n";
    else
      cout << val << "\n";
  }
  return 0;
}
