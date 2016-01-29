/*
 int mat[R][C] = { {1, 2, 3},
 {4, 6, 5},
 {3, 2, 1}
 };                    
 k = 12;

 pathCount(mat, int i, int j, int k) {
   if (!isValid(i, j))
   return 0;

   if (k == 0 && i == R -1 && j == C - 1)
   return 1;

   return pathCount(mat, i + 1, j, k - mat[i][j])
   + pathCount(mat, i, j + 1, k - mat[i][j])
 }
 
*/

#include <iostream>
using namespace std;

#define R 3
#define C 3


bool isValid(int i, int j) {
  if (i < 0 || i >= R)
    return false;
  if (j < 0 || j >= C)
    return false;
  return true;
}

int pathCount(int mat[][C], int i, int j, int k) {
  if (!isValid(i, j))
    return 0;

  int x = k - mat[i][j];
  if (x == 0 && i == R - 1 && j == C -  1)
    return 1;

  return pathCount(mat, i + 1, j, x)
    + pathCount(mat, i, j + 1, x);

}

int main() {
 int mat[R][C] = { {1, 2, 3},
                   {4, 6, 5},
                   {3, 2, 1}
 };                    
  int  k = 12;
  cout << "\n\n" << pathCount(mat, 0, 0, k) << "\n\n";
  return 0;
}
