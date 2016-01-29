/*
5 6
1 2 3 4 1
3 4 1 2 1 3

1 2 3

dyn_prog :

void subsequence(int arr1[], int arr2[], int m, int n, vector<int> &common) {
  int lcs[m + 1][n + 1];

for (int i = 0; i <= m; ++i)
  for (int j = 0; j <= n; ++j) {
    if (i == 0 || j == 0)
      lcs[i][j] = 0;
    else if (arr[i - 1] == arr2[j - 1]) {
      common.push_back(arr[i - 1]);
      lcs[i][j] = 1 + lcs[i - 1][j - 1]
    } else {
      lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
    }
  }
}
 */
#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
using namespace std;

void subsequence(int arr1[], int arr2[], int m, int n) {
  int lcs[m + 1][n + 1];
  for (int i = 0; i <= m; ++i)
    for (int j = 0; j <= n; ++j) {
      if (i == 0 || j == 0)
        lcs[i][j] = 0;
      else if (arr1[i - 1] == arr2[j - 1]) {
        lcs[i][j] = 1 + lcs[i - 1][j - 1];
      } else {
        lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
      }
    }

  int index = lcs[m][n];
  int seq[index];
  int i = m;
  int j = n;

  while (i > 0 && j > 0) {
    if (arr1[i - 1] == arr2[j - 1]) {
      seq[index - 1] = arr1[i - 1];
      --i; --j; --index;
    } else if (lcs[i - 1][j] > lcs[i][j - 1])
      --i;
    else
      --j;
  }

  index = lcs[m][n];
  for (int i = 0; i < index; ++i)
    cout << seq[i] << " ";
}

int main() {
  ifstream in("input1.txt");
  int m, n;
  in >> m >> n;
  int arr1[m], arr2[n];
  for (int i = 0; i < m; ++i)
    in >> arr1[i];
  for (int i = 0; i < n; ++i)
    in >> arr2[i];
  subsequence(arr1, arr2, m, n);
  return 0;
}
