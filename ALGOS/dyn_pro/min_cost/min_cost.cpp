#include<iostream>
#include <cstdio>
using namespace std;

int minCost(int **cost, int m, int n) {
  int min[m + 1][n + 1];
  minC[0][0] = 0;
  for (unsigned i = 0; i <=m; ++i)
    for (unsigned j = 0; j <= n; ++j) {
      if (i == 0)
        minC[i][j] =  cost[i][j] + minC[i][j - 1];
      else if (j == 0)
        minC[i][j] = cost[i - 1][]
       minC[i][j] = cost[i][j] + min(min(minC[i][j - 1],
                                        minC[i - 1][j]),
                                    minC[i - 1][j - 1]); 
    }
}

/* Driver program to test above functions */
int main()
{
  int cost[R][C] = { {1, 2, 3},
                     {4, 8, 2},
                     {1, 5, 3} };
  printf(" %d ", minCost(cost, 2, 2));
  return 0;
}
