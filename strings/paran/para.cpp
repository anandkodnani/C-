#include <iostream>
#include <string>
using namespace std;

int depth(string str) {
  int max_depth = 0, curr_depth = 0;
  for (unsigned i = 0; i < str.length(); ++i) {
    if (str[i] == '(')
      curr_depth += 1;
    else if (str[i] == ')')
      curr_depth -= 1;

    if (curr_depth > max_depth)
      max_depth = curr_depth;
  }
  return max_depth;
}

int main() {
  string str = "( a(b) (c) (d(e(f)g)h) I (j(k)l)m)";
  cout << "\n\n" <<depth(str);
  return 0;
}
