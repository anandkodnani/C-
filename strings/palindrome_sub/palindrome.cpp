/*
  1. Find all the palindrome substrings using dynamic program.
  for (len = 2; len < str.length(); ++len)
   for (i = 0; i < str.length() - len + 1; ++i) {
     int j = i + len -1;
     if (len == 2 && str[i] ==  str[j])
     P[i][j] = (str[i] == str[j]);
     else
     P[i][j] = (str[i] == str[j]) && P[i + 1][j - 1];
   }

  2. for (i : 0 to  len)
       for (j : 0 to len)
       if (P[i][j])
       insert in set;
*/

#include <iostream>
#include <string>
#include <set>
#include <cstring>
using namespace std;

void printPalindrome(string str) {
  int len = str.length();
  bool Palin[len][len];
  set<string> store;
  memset(Palin, false, sizeof(Palin));

  // All the substrings of size 1 are palindrome.
  for (unsigned i = 0; i < len; ++i)
    Palin[i][i] = true;

  // Find all palindromic substrings.
  for (unsigned l = 2; l <= len; ++l )
    for (unsigned i = 0; i < len - l + 1; ++i) {
      int j = i + l - 1;
      if (l == 2)
        Palin[i][j] = (str[i] == str[j]);
      else
        Palin[i][j] = (str[i] == str[j]) && Palin[i + 1][j - 1];
    }

  for (unsigned i = 0; i < len; ++i)
    for (unsigned j = 0; j < len; ++j)
      if (Palin[i][j])
        store.insert(str.substr(i, j - i + 1));
        
  for (auto str : store)
    cout << "\n\n" << str;
}

int main() {
  string str = "abaaaa";
  printPalindrome(str);
  return 0;
}
