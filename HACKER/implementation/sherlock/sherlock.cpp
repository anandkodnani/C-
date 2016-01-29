#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;

string getNumber(int fiveCount, int threeCount) {
  string str = "";
  while (fiveCount > 0) {
    str += "5";
    fiveCount--;
  }

  while (threeCount > 0) {
    str += "3";
    threeCount--;
  }
  return str;
}

int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  ifstream in("input3.txt");
  int numTestCase;
  in >> numTestCase;

  for (int i = 0; i < numTestCase; ++i) {
    int numDigits;
    in >> numDigits;

    if (numDigits < 3) {
      cout << "-1\n";
    } else if (numDigits == 3) {
      cout << "555\n";
    } else if (numDigits == 5) {
      cout << "33333\n";
    } else {
      int count = numDigits;
      int threeCount = 0;
      while (count % 3 != 0) {
        threeCount += 5;
        count -= 5;
      }
      if (count < 0)
        cout << "-1\n";
      else
        cout << getNumber(count, threeCount) << "\n";

    }

  }
  return 0;
}
