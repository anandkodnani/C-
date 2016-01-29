#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;


int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  ifstream infile("input.txt");
  unsigned numTestCases = 0;
  infile >> numTestCases;
  for (unsigned n = 0; n  < numTestCases; ++n) {
    // Load the Grid.
    unsigned R = 0, C = 0;
    infile >> R >> C;
    int **G;
    G = new int *[R];
    for (unsigned i = 0; i < R; ++i)
      G[i] = new int[C];
    
    for (unsigned i = 0; i < R; ++i)
      for (unsigned j = 0; j < C; ++j) {
        int val = 0;
        infile >> val;
        G[i][j] = val;
      }

    // Load the pattern
    unsigned r = 0, c = 0;
    infile >> r >> c;
    int **P;
    P = new int *[r];
    for (unsigned i = 0; i < r; ++i)
      G[i] = new int[c];
    
    for (unsigned i = 0; i < r; ++i)
      for (unsigned j = 0; j < c; ++j) {
        int val = 0;
        infile >> val;
        P[i][j] = val;
      }

  }
  return 0;
}
