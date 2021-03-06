/*
Input: bool mat[n][n] = { {1, 0, 0, 0},
                          {1, 1, 1, 0},
                          {1, 1, 0, 0},
                          {1, 1, 1, 0},
                        };
Output: 0

O(n)
   1. Go through all diagonal elements.
   2. Check all elements of the row for 0 and column for 1.
   3. If matched return k else return -1.
*/

#define N 5
#include <iostream>
using namespace std;

int checkElement(int mat[][N], int k) {
  int val = -1;
  for (unsigned i = 0; i < N; ++i)
    if (mat[k][i] != 0 && i != k)
      return -1;

  for (unsigned i = 0; i < N; ++i)
    if (mat[i][k] != 1 && i != k)
      return -1;
  return k;
}

int main() {
  int mat[N][N] = {{0, 1, 1, 0, 1},
                    {0, 0, 0, 0, 0},
                    {1, 1, 1, 0, 0},
                    {1, 1, 1, 1, 0},
                    {1, 1, 1, 1, 1}};
  // Iterate through all the diagonal elements.
  for (unsigned i = 0; i < N; ++i) {
    int x = checkElement(mat, i);
    if(x != -1) {
      cout << "\n\n" << i << "\n\n";
      return 0;
    }
  }
  cout << "\n\n -1 \n\n";
  return 0;
}
