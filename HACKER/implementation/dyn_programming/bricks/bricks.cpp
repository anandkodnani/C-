/*
2
5
999 1 1 1 0
5
0 1 1 1 999

recursive solution:


 */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

/*unsigned long long max_score(int arr[], int N, int index, bool move,
                             vector<unsigned long long> &myscore) {
  if (index >= N)
    return 0;
  
  unsigned long long  move1, move2, move3;
  move1 = 0; move2 = 0; move3 = 0;
  if (index  < N)
    move1 = arr[index] + max_score(arr, N, index + 1, move ? false :true,
                                   myscore);

  if (index + 1 < N)
    move2 = arr[index] + arr[index + 1] +
      max_score(arr, N, index + 2, move ? false :true, myscore);

  if (index + 2 < N)
    move3 = arr[index] + arr[index + 1] + arr[index + 2] +
      max_score(arr, N, index + 3, move ? false :true, myscore);

  unsigned long long max_val = 0;
  max_val = (move1 > move2) ? move1 : move2;
  max_val = (max_val > move3) ? max_val : move3;

  //if (!move)
    myscore.push_back(max_val);
  return max_val;
  }*/

int long long max_score(int long long arr[], int N) {
  // Create the sum array.
  int long long sum[N];
  sum[0] = arr[0];
  for (int i = 1; i < N; ++i)
    sum[i] = sum[i - 1] + arr[i];

  int dp[N];
  dp[0] = arr[0];
  dp[1] = dp[0] + arr[1];
  dp[2] = dp[1] + arr[2];

  int long long val = -1;
  for (int i = 3; i < N; ++i) {
    val = max(val, sum[i - 1] - dp[i - 1] + arr[i]);
    val = max(val, sum[i - 2] - dp[i - 2] + arr[i] + arr[i - 1]);
    val = max(val, sum[i - 3] - dp[i - 3] + arr[i] + arr[i - 1] + arr[i - 2]);
    dp[i] = val;
  }
  return dp[N - 1];
}

int main() {
  ifstream in("input1.txt");
  int numTestCase;
  in >> numTestCase;

  for (int i = 0; i < numTestCase; ++i) {
    int N;
    in >> N;
    int long long arr[N];
    for (int j = N - 1; j >= 0; --j) {
      in >> arr[j];
    }
    cout << max_score(arr, N) << "\n";

  }
  return 0;
}
