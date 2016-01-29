/*
  1. 1
  2. x = 2*1 +1
  3. x = 2*x
  
 */


#include <iostream>
#include <fstream>
using namespace std;

int main() {
  ifstream in("input.txt");
  int numTestCase = 0;
  in >> numTestCase;

  for (int i = 0; i < numTestCase; ++i) {
    int cycles = 0;
    int init = 1;
    in >> cycles;
    int x = cycles / 2;
    int rem = cycles % 2;
    for (int i = 0; i < x; ++i) {
      init = 2 * init + 1;
    }

    if (rem == 1)
      init = 2 * init;

    cout << init << "\n";
  }
  return 0;
}

