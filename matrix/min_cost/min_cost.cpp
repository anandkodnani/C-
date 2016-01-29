/*
Input: points[m][n] = { {-2, -3,   3}, 
                        {-5, -10,  1}, 
                        {10,  30, -5} 
                      };

-2 + mincost(i, j + 1)
-2 + mincost(i + 1, j)
-2 + mincost(i + 1, j + 1)
 */

#include <iostream>
#include <algorithm>
using namespace std;
#define R 3
#define C 3

int minInitialPoints(int points[][C], int i, int j) {
  if (i < 0 || i >= R - 1|| j < 0 || j >= C - 1)
    return 0;
  int max_val =  points[i][j] + max(max(minInitialPoints(points, i + 1, j),
                                    minInitialPoints(points, i, j + 1)),
                                minInitialPoints(points, i + 1, j + 1));
  max_val = max_val + abs(points[R - 1][C - 1]) + 1;
  return max_val;
}

// Driver Program
int main()
{
 
  int points[R][C] = { {-2,-3,3},
                       {-5,-10,1},
                       {10,30,-5}
  };
  cout << "Minimum Initial Points Required: "
       << minInitialPoints(points, 0, 0);
  return 0;
}
