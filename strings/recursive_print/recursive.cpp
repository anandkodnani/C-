#include <iostream>
#include <string>
using namespace std;

void printUtil(string arr[3][3], int r, int c, string output[3]) {
  output[r] = arr[r][c];

  if (r == 2) {
    for (unsigned i = 0; i < 3; ++i)
      cout << " " << output[i];
    cout << "\n\n";
    return;
  }

  for (unsigned i = 0; i < 3; ++i) {
    if (!arr[r + 1][i].empty()) {
      printUtil(arr, r + 1, i, output);
    }
  }
  cout << "\n\n";
}

void print(string arr[3][3]) {
  string output[3];
  for (unsigned i = 0; i < 3; ++i)
    if (!arr[0][i].empty())
      printUtil(arr, 0, i, output);
}

int main() {
  string arr[3][3] = {{"you", "we"}, {"have", "are"},
                      {"sleep", "eat", "drink"}};
  print(arr);
  return 0;
}
