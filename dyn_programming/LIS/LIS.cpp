#include <iostream>
#include <fstream>
using namespace std;

int lis(int *arr, int size) {
  int LIS[size];
  for (int i = 0; i < size; ++i)
    LIS[i] =  1;

  for (int i = 0; i < size; ++i)
    for (int j = 0; j < i; ++j) {
      if (arr[i] > arr[j] && LIS[i] < LIS[j] + 1)
        LIS[i] = LIS[j] + 1;
    }
  int max = 0;
  for (int i = 0; i < size; ++i)
    if (max < LIS[i])
      max = LIS[i];
  return max;
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
