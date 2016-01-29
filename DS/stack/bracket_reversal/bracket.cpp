/*
Input:  exp = "{{{{"
Output: 2 
Input:  exp = "{{{{}}"
Output: 1 

Input:  exp = "}{{}}{{{"
Output: 3

1. put { on stack.
2. for } pop and element from stack.
 */

#include <iostream>
#include <stack>
using namespace std;

int main() {
  char *str = "{{{{}}";
  stack<char> st1;
  stack<char> st2;
  int len = strlen(str);
  for (int i = 0; i < len; ++i) {
    if (str[i] == '{') {
      if (!st2.empty())
        st2.pop();
    }
  }
  return 0;
}
