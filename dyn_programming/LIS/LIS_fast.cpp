#include <iostream>
#include <fstream>
using namespace std;

int getPosition(int arr[], int l, int r, int val) {
  while (r - l > 1) {
    int m = l + (r - l) / 2;
    if (arr[m] >= val)
      r = m;
    else
      l = m;
  }
  return r;
}

int lis(int *arr, int size) {
  int table[size];
  table[0] = arr[0];
  int len = 1;

  for (int i = 1; i < size; ++i) {
    if (arr[i] < table[0])
      table[0] = arr[i];
    else if (arr[i] > table[len - 1])
      table[len++] = arr[i];
    else {
      int pos = getPosition(table, -1, len - 1, arr[i]);
      table[pos] = arr[i];
    }
  }
  return len;
}

int main()
{
  ifstream in("input.txt");
  int N;
  in >> N;
  int arr[N];

  for (int i = 0; i < N; ++i)
    in >> arr[i];

  cout << lis(arr, N); 
  return 0;
}
