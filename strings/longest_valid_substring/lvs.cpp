// Pg.1 question 2.
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int findMaxLen(string str) {
  stack<int> S;
  S.push(-1);
  int result = 0;

  for (unsigned i = 0; i < str.length(); ++i) {
    if (str[i] == '(')
      S.push(i);
    else if (str[i] == ')') {
      S.pop();
      if (S.empty())
        S.push(i);
      else {
        result = (i - S.top()) > result ? (i - S.top()) : result;
      }
    }
  }
  return result;
}
// Driver program
int main()
{
  string str = "((()()";
  cout << findMaxLen(str) << endl;
 
  str = "()(()))))";
  cout << findMaxLen(str) << endl ;
 
  return 0;
}
