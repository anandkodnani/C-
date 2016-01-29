#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int  editDist(string str1, string str2, int len1, int len2) {
  if (len1 == 0)
    return len2;

  if (len2 == 0)
    return len1;

  int edit[len1 + 1][len2 + 1];
  for (unsigned i = 0; i <= len1; ++i)
    for (unsigned j = 0; j <= len2; ++j) {
      if (i == 0)
        edit[i][j] = j;
      else if (j == 0)
        edit[i][j] = i;
      else if (str1[i] == str2[j])
        edit[i][j] = edit[i - 1][j - 1];
      else {
        edit[i][j] =  1 + min(min(edit[i - 1][j],
                                  edit[i][j - 1]),
                              edit[i - 1][j - 1]);
      }
    }
  return edit[len1][len2];
}

int main() {
  string str1 = "sunday";
  string str2 = "saturday";
  cout << editDist(str1, str2, str1.length(), str2.length());
  return 0;
}
