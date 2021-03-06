//Pg.1 question 1.
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

bool isAlpha(char c) {
  return (c >= 'A' && c <= 'Z' ||
          c >= 'a' && c <= 'z');
}

void reverse(char *str) {
  int r = strlen(str) - 1, s = 0;
  while (s < r) {
    if (!isAlpha(str[s])) {
      ++s;
      continue;
    }
    if (!isAlpha(str[r])) {
      --r;
      continue;
    }
    swap(str[s], str[r]);
    ++s;
    --r;
  }
}

int main() {
  char str[] = "a!!!b.c.d,e'f,ghi";
  cout << "Input string: " << str << endl;
  reverse(str);
  cout << "Output string: " << str << endl; 
  return 0;
}
