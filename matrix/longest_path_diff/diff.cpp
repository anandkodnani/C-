/*
Input:  mat[][] = {{1, 2, 9}
                   {5, 3, 8}
                   {4, 6, 7}}
Output: 4

int longestPath(mat, i, j, prev) {
   !isValid(i, j)
   return 0;

   int result = 0;
  (mat[i][j] - prev == 1)
  result = 1;

  return 
  max (1 + longestPath(i + 1, j), 1 + longestPath(i - 1, j),
  longestPath(i, j + 1), longestPath(i, j - 1));
}
*/


#define R 2
#define C 2

#include <iostream>
#include <algorithm>
using namespace std;

bool isValid(int i, int j) {
  if (i < 0 || i >= R)
    return false;
  if (j < 0 || j >= C)
    return false;
  return true;
}

int longestPath(int mat[][C], int i, int j, int prev) {
  if (!isValid(i, j))
    return 0;
  
  int result = 0;
  if (mat[i][j] - prev == 1)
    result = 2;
  if (prev == -1)
    result = 0;
  int previous = mat[i][j];

  return result + max( max(longestPath(mat, i + 1, j, previous),
                           longestPath(mat, i -1, j, previous)),
                       max(longestPath(mat, i, j + 1, previous),
                           longestPath(mat, i, j - 1, previous)));
}

int main() {
    int mat[R][C] = {{1, 2},
                     {5, 3}};
    cout << "\n\n" << longestPath(mat, 0, 0, -1) << "\n\n";
  return 0;
}
