/*
4 3
1 2 3 

Recursive solution:

coin_change (int coins[], int sum, int k) {
  if (sum < 0)
    return 0;

  if (k < 0)
    return 0;

   if (sum == 0)
     return 1;
    if (sum < coin[k])
    return coin_change();

return coin_change(coins, sum - coin[k], k - 1)
  + coin_change(coins, sum, k - 1);
}


dyn_prog solution:

dp[sum + 1][N];
change;

for (i = sum;  i >= 0; --i) 
  for (j = N - 1; j >= 0; --j) {
  
  }
       
 */
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void coin_change(int coins[], int sum, vector<int> &change, int k) {

  if (sum < 0)
    return;

  if (sum == 0) {
    // print the vector.
    cout << "\n\n";
    for (auto &i : change)
      cout << i << " ";
    cout << "\n\n";
    return;
  }

  if (k < 0)
    return;

  if (sum < coins[k])
    return coin_change(coins, sum, change, k - 1);

  // Find the highest divisor of sum and coin[k];
  // Iterate through all the all the elements.
  int div = sum / coins[k];
  int c_change = 0;
  for (int i = 0; i <= div; ++i) {
    int limit = 0;
    while (limit < i) {
      change.push_back(coins[k]);
      limit++;
    }
    coin_change(coins, sum - i*coins[k], change, k - 1);
    limit = 0;
    while (limit < i) {
      change.pop_back();
      limit++;
    }    
  }
}

int main() {
  ifstream in("input.txt");
  int sum, N;
  in >> sum >> N;
  int coins[N];
  for (int i = 0; i < N; ++i)
    in >> coins[i];

  vector<int> change;
  coin_change(coins, sum, change, N - 1);
  return 0;
}
