/*Given a value V, if we want to make change for V Rs,
  and we have infinite supply of each
  of the denominations in Indian currency,
  i.e., we have infinite supply of
  { 1, 2, 5, 10, 20, 50, 100, 500, 1000} valued
  coins/notes, what is the minimum number of coins and/or
  notes needed to make the change?
  Examples:
  Input: V = 70
  Output: 2
We need a 50 Rs note and a 20 Rs note.

  Input: V = 121
  Output: 3
  We need a 100 Rs note, a 20 Rs note and a 
  1 Rs coin. */

#include<iostream>
#include <vector>
using namespace std;
// All denominations of Indian Currency
int deno[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
int n = sizeof(deno)/sizeof(deno[0]);

void findMin(int val) {
  vector<int> res;
  int start = n - 1;
  while (val > 0) {
    for (int i = start; i >= 0; --i) {
      if (deno[i] > val)
        continue;
      val = val - deno[i];
      res.push_back(deno[i]);
      start = i;
      break;
    }
  }
  for (auto i : res)
    cout << " " << i;
}

// Driver program
int main()
{
  int val = 93;
  cout << "Following is minimal number of change for " << n << " is ";
  findMin(val);
  return 0;
}
