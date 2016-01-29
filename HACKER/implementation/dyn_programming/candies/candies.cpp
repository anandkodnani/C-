/*

3  
1  
2  
2

// 1 2 3 3 5

  1 + 2 + 3 + 1 + 2 = 9

// 1 2 3 4 5 9 9 2

   1 + 2 + 3 + 4 + 5 + 6 + 2 + 1 = 

10
2
4
2
6
1
7
8
9
2
1

 1 2 1 2 1 2 3 4 2 1 = 19

 1 2 1 2 1 2 3 4 2 1

recursive :
 
dyn_programming:

int min_candies(int arr[], int start, int N) {
  int dp[N + 1];

// Initialize all elements to 1.
  
  for (int i = 1; i < N; ++i) {
    if (arr[i] < arr[i - 1]) {
      dp[i - 1] = 1 + dp[i];
    } else if (arr[i] > arr[i - 1])
      dp[i] = 1 + dp[i - 1];
    else
      dp[i] = 1;
  }
   
}
*/

#include <iostream>
#include <fstream>
using namespace std;

int min_candies(int arr[], int N) {
  int dp[N];

  // Initialize all elements to 1.
  for (int i = 0; i < N; ++i)
    dp[i] = 1;

  for (int i = 1; i < N; ++i) {
    if (arr[i] < arr[i - 1]) {
      int j = i;
      while (j - 1 >= 0 && arr[j] < arr[j - 1] &&
             dp[j - 1] <= dp[j]) {
        dp[j - 1] = 1 + dp[j];
        --j;
      }
    } else if (arr[i] > arr[i - 1])
      dp[i] = 1 + dp[i - 1];
    else
      dp[i] = 1;
  }

  int sum = 0;
  for (int i = 0; i < N; ++i)
    sum += dp[i];

  return sum;  
}

int main() {
  ifstream in("input.txt");
  int N;
  in >> N;
  int arr[N];

  for (int i = 0; i < N; ++i) {
    in >> arr[i];
  }
  cout << min_candies(arr, N);
  return 0;
}
