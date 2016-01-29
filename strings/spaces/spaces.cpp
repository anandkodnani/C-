/*
  "ABCD"
  print    print
  A        BCD
           print   print
           B       CD
                   print print
                   C     D

*/

void printUtil(string str, int i, string buf[], int spaces) {
  if (spaces == 0) {
    for (unsigned i = 0; i < sizeof(buf)/ sizeof(buf[0]); ++i)
      cout << " " << buf[i];
    cout << "\n\n";
  }
  string firstString = str.substr(0, i + 1);
  string secondString =  str.substr(i + 1, str.length() - i);
  
}

void print(string str) {
  int len = str.length();
  string buf[len];
  memset(buf, "", sizeof(buf));
  
  for (unsigned i = 0; i < len; ++i) {
    printUtil(str, i, buf, 1);
  }
}

int main() {
  string str = "ABCD";
  print(str);
  return 0;
}
