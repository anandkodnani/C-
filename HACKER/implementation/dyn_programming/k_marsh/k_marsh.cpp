#include <iostream>
#include <fstream>
using namespace std;
int M = -1;
int N = -1;
char **arr;
int perimeter() {
  int dpi[M + 1][N + 1];
  int dpj[M + 1][N + 1];
  for (int i = 0; i <= M; ++i)
    for (int j = 0; j <= N; ++j) {
      if (i == 0 || j == 0) {
        dpi[i][j] = 0;
        dpj[i][j] = 0;
      } else if (arr[i][j] == '.'){
        dpi[i][j] = 1 + dpi[i - 1][j];
        dpj[i][j] = 1 + dpj[i][j - 1]; 
      } else {
        dpi[i][j] = 0;
        dpj[i][j] = 0;
      }
    }

  for (int i = 0; i <= M; ++i) {
    cout << "\n";
    for (int j = 0; j <= N; ++j) {
      cout << "(" << dpi[i][j] << "," 
           << dpj[i][j] << ")"<< " ";
    }
  }

  int max = -1;
  int max_i = -1;
  int max_j = -1;

  for (int i = 0; i <= M; ++i) {
    for (int j = 0; j <= N; ++j) {
      max_i = min(dpi[i][j], dpi[i][j - dpj[i][j] + 1]);
      max_j = min(dpj[i][j], dpj[i - dpi[i][j] + 1][j]);
      if (max < 2 * (max_i + max_j - 2))
        max = 2 * (max_i + max_j - 2);
    }
  }
  return max;
}


int main() {
  ifstream in("input4.txt");
  in >> M;
  in >> N;
  arr = new char*[M + 1];
  for (int i = 0; i <= M; ++i)
    arr[i] = new char[N + 1];

  for (int i = 1; i <= M; ++i)
    for (int j = 1; j <= N; ++j)
      in >> arr[i][j];

  int val = perimeter();
  if (val <= 0)
    cout << "impossible";
  else
    cout << val;

  for (int i = 0; i <= M; ++i )
    delete [] arr[i];
  delete []arr;
  return 0;
}
