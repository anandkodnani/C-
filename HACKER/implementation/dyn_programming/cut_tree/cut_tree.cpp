/*
unsigned long long getSum(string str) {
  int N = str.length();
  unsigned long long dp[N][N];
  for (int i = 0; i < N; ++i) {
    for (int j = i; j < N; ++j) {
      if (i == j)
        dp[i][j] = (str[i] - '0') % 1000000007;
      else {
        dp[i][j] = 10 * dp[i][j - 1] + (str[j] - '0');
        dp[i][j] = dp[i][j] % 1000000007;
      }
    }
  }
}
 
input = 16;

1. i = 0 j = 0
  dp[0][0] = 1;

2. i = 0 j = 1
   dp[0][1] = 16;

3. i = 1 j = 1
   dp[1][1] = 6

return sum


input = 123

1. i = 0 j = 0
   

*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

unsigned long long **dp;
unsigned long long getSum(string &str) {
  int N = str.length();

  dp = new unsigned long long *[N];
  for (int i = 0; i < N; ++i)
    dp[i] = new unsigned long long[N];
    
  for (int i = 0; i < N; ++i) {
    for (int j = i; j < N; ++j) {
      if (i == j)
        dp[i][j] = (str[i] - '0') % 1000000007;
      else {
        dp[i][j] = ((10 * dp[i][j - 1]) % 1000000007
                    + (str[j] - '0')) % 1000000007;
      }
    }
  }

  unsigned long long sum = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = i; j < N; ++j) {
      sum += dp[i][j];
      sum = sum % 1000000007;
    }
  }
  return sum % 1000000007;
}

int main () {
  ifstream in("input1.txt");
  string str;
  cin >> str;

  cout << getSum(str);
  int N = str.length();
  for (int i = 0; i < N; ++i)
    delete [] dp[i];
  delete [] dp;
  return 0;
}
