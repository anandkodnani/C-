// Pg.1 question 3.
#include <iostream>
#include <string>
#include <map>
using namespace std;


bool areIsomorphic(string str1, string str2) {
  if (str1.length() != str2.length())
    return false;
  for (unsigned i = 0; i < str1.length(); ++i) {
    
  }
}

// Driver program
int main()
{
  cout << areIsomorphic("aab", "xxy") << endl;
  cout << areIsomorphic("aab", "xyz") << endl;
  return 0;
}
