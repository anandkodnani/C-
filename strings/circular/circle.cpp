#include <iostream>
#include <string>
using namespace std;

bool isCircular(char *str) {
  int x = 0, y = 0, lcount = 0, rcount = 0;
  while (str[0] != '\0') {
    int count = (lcount - rcount) % 4;
    
    switch(str[0]) {
    }
  }
}

int main() {
  char *str = "GLGLGLG";
  if (isCircular(str))
    cout << "\n\n" << "is circle";
  else
    cout << "\n\n" << "not is circle"
  return 0;
}
