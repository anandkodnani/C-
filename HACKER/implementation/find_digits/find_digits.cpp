#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main() {
  ifstream in("input.txt");
  int numTestCase = 0;
  in  >> numTestCase;

  for (int i = 0; i < numTestCase; ++i) {
    int long num = 0;
    in >> num;
    int digits[10];
    bool multiple[10];
    memset(digits, 0, sizeof(digits));
    memset(multiple, false, sizeof(multiple));
    int orig = num;
    while (num > 0) {
      int x = num % 10;
      if (x != 0 && orig % x == 0) {
        digits[x]++;
        multiple[x] = true;
      }
      num = num / 10;
    }
    int final = 0;
    for (int i = 0; i < 10; ++i) {
      if (multiple[i])
        final += digits[i];
    }
    cout << final << "\n";
  }
  return 0;
}
