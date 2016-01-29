/*
Input:  mat[][] = {{1, 2, 9}
                   {5, 3, 8}
                   {4, 6, 7}}

int longest_path(int mat[][C], int i, int j, int prev) {
if (i < 0 || i >= R || j < 0 || j >= C)
return 0;


if (mat[i][j] - prev != 1)
return 0;

return 1 + max((i - 1, j))
}

dyn_programming:

int longest_path(int mat[][C], int i, int j) {

int dp[R][C];

dp[0][0] = 0;

// Handle all row = 0 cases;
for (int i = 1; i < C; ++i)
if (mat[0][i] - mat[0][i - 1] ==  1)
dp[0][i] = 2 + dp[0][i - 1];
else 
dp[0][i] = 0 + dp[0][i - 1];


for (int i = 1; i < R; ++i)
if (mat[i][0] - mat[i - 1][0] ==  1)
dp[i][0] = 2 + dp[i - 1][0];
else 
dp[0][i] = 0;

for (int i = 1; i < R; ++i)
for (int j = 1; j < C; ++j) {

if (i < 0 || i >= R || j < 0 || j >= C)
continue;

if (i == 0 || j == 0)
}

}
 */
