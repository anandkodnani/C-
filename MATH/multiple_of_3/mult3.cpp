#include<iostream>
#include<cstdlib>
using namespace std;

int isMultiple3(unsigned x) {
  x = (x < 0) ? -x : x;
  if (x == 0)
    return 1;
  else if (x == 1)
    return 0;
  unsigned EvenCount = 0, OddCount = 0;
  bool Even = true;
  while (x != 0) {
    if (x & 1) {
      if (Even)
        ++EvenCount;
      else
        ++OddCount;
    }
    Even = !Even;
    x = x >> 1;
  }
  return isMultiple3(EvenCount - OddCount);
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    cout << "No input argument";
    return 0;
  }

  unsigned x = atoi(argv[1]);
  if (isMultiple3(x))
    cout << x << " is a multiple of 3";
  else
    cout << x << " is not a multiple of 3";

  return 0;
}
