/*

mat[][] = { {1, 2, 3},
{4, 6, 5},
{3, 2, 1}
};

recursive solution:

path_count(mat, i, j, k) {
  if (i < 0 || i >=R || j < 0 || j >= C)
    return 0;}

dynamic program:
use memoization here because we don't have to compute
all elements of matrix dp.

  int dp[R][C][k];
int path_count(int mat[][C], int i, int j, int k) {

if (i < 0 || i >= R || j < 0 || j >= C)
return 0;

if (dp[i][j][k] != -1)
return dp[i][j][k];

dp[i][j][k] = path_count() + path_count();
return dp[i][j][k];
}

}

 */
#include <iostream>
#include <cstring>
 using namespace std;
#define R 3
#define C 3
#define K 12
 /*int path_count(int mat[][C], int i, int j, int k) {
   if (i < 0 || i >=R || j < 0 || j >= C)
     return 0;
   
   if (k == mat[R - 1][C - 1] && i == R - 1 && j == C - 1)
     return 1;

   return path_count(mat, i + 1, j, k - mat[i][j]) +
     path_count(mat, i, j + 1, k - mat[i][j]); 
 }*/

int path_count_dp (int mat[][C], int i, int j, int k, int dp[][C][K]) {
   if (i < 0 || i >=R || j < 0 || j >= C)
     return 0;
   
   if (k == mat[R - 1][C - 1] && i == R - 1 && j == C - 1)
     return 1;

   if (dp[i][j][k] != -1)
     return dp[i][j][k];

   dp[i][j][k] = path_count_dp(mat, i + 1, j, k - mat[i][j], dp) +
     path_count_dp(mat, i, j + 1, k - mat[i][j], dp);
   return dp[i][j][k];
}

 int main () {
   int mat[R][C] = { {1, 2, 3},
                   {4, 6, 5},
                   {3, 2, 1}
   };
   int k = 12;
   int dp[R][C][K];
   memset(dp, -1, sizeof(dp));
   cout << "\n\nThe number of paths : "
        << path_count_dp(mat, 0, 0, k, dp) << "\n\n";
   return 0;
 }
