/*
4 3
1 2 3 

output : 4

recursive:

int coin_change(int coins[], int sum, int k) {

 if (sum < 0)
  return 0;

 if (sum == 0)
   return 1;


 if (k < 0)
   return 0;

 if (sum < coins[k])
  return coin_change(coins, sum, k - 1);

 // iterate through the array.
 int div = sum / coins[k];
 int val = 0;
 for (int i = 0; i <= div; ++i) {
   val += coin_change(coins, sum - i * coins[k], k - 1);
 }

 return val;
}

dyn_programming:

int coin_change(int coins[], int sum, int k) {

  int dp[sum + 1][N];

  for (int i = 0; i <= sum; ++i) { 
   dp[i][0] = 0;
   dp[0][i] = 0;
  }

  for (int i = 1; i <= sum; ++i) {
    for (int j = 1; j < N; ++j) {
      if (i == coins[j])
       dp[i][j] = 1;
      else if (i < coins[j])
       dp[i][j] = dp[i][j -  1];
      else {
      int div = i / coins[j];
      for (int l = 0; l <= div; ++l) {
       dp[i][j] += dp[i - l * coins[j]][j - 1];
      }
     }

    }
  }
return dp[sum][N];
}
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int coin_change(int coins[], int sum, int k) {


 if (sum < 0)
   return 0;

 if (sum == 0)
   return 1;

 if (k < 0)
   return 0;

 if (sum < coins[k])
   return coin_change(coins, sum, k - 1);


 // iterate through the array.
 int div = sum / coins[k];
 int val = 0;
 for (int i = 0; i <= div; ++i) {
   val += coin_change(coins, sum - i * coins[k], k - 1);
 }

 return val;
 }

unsigned long long  coin_change1(int coins[], int sum, int N) {

  unsigned long long  dp[sum + 1][N];

  memset(dp, 0, sizeof(dp));
  for (int i = 0; i <= sum; ++i) { 
    dp[i][0] = 0;
  }

  for (int i = 0; i < N; ++i)
    dp[0][i] = 0;

  for (int i = 1; i <= sum; ++i) {
    for (int j = 0; j < N; ++j) {
      if (i < coins[j]) {
        if (j == 0)
          dp[i][j] = dp[i][j];
        else 
          dp[i][j] = dp[i][j -  1];
        //cout << "\n" << "i = " << i << "j ="
        //   << j << "  val = " << dp[i][j];
      }
      else {
        if (i % coins[j] == 0)
          dp[i][j] +=  1;

        int div = i / coins[j];
        for (int l = 0; l <= div; ++l) {
          if (j == 0) {
            break;
          } else
            dp[i][j] += dp[i - l * coins[j]][j - 1];
        }
        
        //cout << "\n" << "i = " << i << "j ="
        //   << j << "  val = " << dp[i][j];
      }   
    }
  }
  return dp[sum][N - 1];
}

int main() {
  ifstream in("input3.txt");
  int sum, N;
  in >> sum >> N;
  int coins[N];
  int val;
  for (int i = 0; i < N; ++i) {
    in >> val;
    coins[i] = val;
  }
  sort(coins, coins + N);
  cout << "\n\n";
  for (int i = 0; i < N; ++i)
    cout << " " << coins[i];
  cout << "\n\n";
  cout << coin_change1(coins, sum, N);
  return 0;
}
