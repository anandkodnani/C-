#include <iostream>
using namespace std;

int partition(char *arr,  int low, int high, int pivot) {
  int i = low;
  int j = high;

  while (i <= j) {
    while (i <= j && arr[i] < pivot)
      ++i;

    while (i <= j && arr[j] > pivot)
      --j;

    if (i <= j) {
      swap(arr[i], arr[j]);
    }
  }
}

void matchPairs(char *nuts, char *bolts, int low, int high, int pivot) {
  int i = low;
  int j = high;

  if (i < j) {
    int p = partition(nuts, low, high, pivot);
    partition(bolts, low, high, pivot);
    matchPairs(nuts, bolts, low, p -  1, bolts[p - 1]);
    matchPairs(nuts, bolts, p, high, bolts[high]);
  }
}

int main() {
  char nuts[] = {'@', '#', '$', '%', '^', '&'};
  char bots[] = {'$', '%', '&', '^', '@', '#'};
  int n = sizeof(nuts) / sizeof(nuts[0]);
  maptchPairs(nuts, bolts, 0, n - 1, bolts[n - 1]);
  return 0;
}
