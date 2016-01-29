//Pg.1 question 4.
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstring>
#include <climits>
using namespace std;

int mini = 0;
bool isPalindrome(string str, int start, int end) {
  while (start < end) {
    if (str[start] != str[end])
      return false;
    start++; end--;
  }
  return true;
}

/*int partition(string str, int start, int end) {
  if (start == end || isPalindrome(str, start, end))
    return 1;
  mini = min(1 + partition(str, start + 1, end), 
             1 + partition(str, start, end - 1));
  return mini;
  }*/

int partition (string str, int start, int end) {
  int len = str.length();
  int L[len][len];
  bool P[len][len];
  memset(P, false, sizeof(P));
  for (unsigned i = 0;  i < len; ++i) {
    P[i][i] = true;
    L[i][i] =  0;
  }


  for (int l = 2; l <= len; ++l)
    for (int i = 0; i < len - l + 1; ++i) {
      int j = i + l - 1;
      if (l == 2)
        P[i][j] = (str[i] == str[j]);
      else
        P[i][j] = (str[i] == str[j]) && P[i + 1][j - 1];

      if (P[i][j])
        L[i][j] = 0;
      else {
        // make cuts for all elements between i and j.
        L[i][j] = INT_MAX;
        for (int k = i; k < j; ++k) {
          L[i][j] = min(L[i][j], L[i][k] + L[k + 1][j] + 1);
        }
      }
    }

  for (int i = 0; i < len; ++i)
    for (int j = 0; j < len; ++j)
      if (P[i][j])
        cout << "\n\n" << str.substr(i, j - i + 1);
 
  return L[0][len - 1];
}

int main() {
  string str = "nitin";
  vector<string> palin;
  cout << "\n\n" << partition(str, 0, str.length() - 1);
  //printPartition(str, 0, str.length() -  1);
  //cout << "\n\n" << mini;
  return 0;
}
