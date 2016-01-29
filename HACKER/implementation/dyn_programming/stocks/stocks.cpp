/*
3
1 2 100

recursive:
int trade_max(int arr[], int start, int N, int profit) {
  // find the min points and buy everthing until then
int i;
int cost = 0;
  for (i = start, i < N; ++i) { 
    if (i + 1 < N && arr[i] > arr[i + 1])
       break;
    else
      cost += arr[i];
  }
profit += (i - start) * arr[i];

} 

dyn_program:

  int trade_max(int arr[], int N) {
    int dp[N];
    int i = 1;
    dp[0] = -arr[0];
    while (i < N) {
      int j = i;
      while (j < N && arr[j] > arr[j - 1]) {
        dp[j] = -arr[j] + dp[j - 1];
        j++;
      }

     // Compute the profit on sell day.
     dp[j - 1] = (j - i - 1) * arr[j - 1];
     if (j == i)
      ++i;
     else
       i = j;
    }

  } 

*/

#include <iostream>
#include <fstream>
using namespace std;

long int trade_max(int arr[], int N) {
  long int max_profit = 0;
  int curr_max = 0;
  for (int i = N - 1; i >= 0; --i) {
    curr_max = max(curr_max, arr[i]);
    max_profit +=(long int)( curr_max - arr[i]);
  }
  return max_profit;
} 

int main() {
  ifstream in("input.txt");
  int numTestCase;
  in >> numTestCase;

  for (int k = 0; k < numTestCase; ++k) {
    int N;
    in >> N;
    int arr[N];

    for (int i = 0; i < N; ++i)
      in >> arr[i];

    cout << trade_max(arr, N) << "\n";
  }
  return 0;
}
