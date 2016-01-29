#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main() {
  int N;
  int numTestCase;
  vector<int> width;
  ifstream in("input.txt");
  string line;
  in >> N;
  in >> numTestCase;
  getline(in, line);
  istringstream iss(line);
  int num;
  while (iss >> num)
    width.push_back(num);

  for (int i = 0; i < numTestCase; ++i) {
    int start, end;
    in >> start;
    in >> end;
    int max = 3;
    for (int i = start; i <= end; ++i)
      if (width[i] < max) {
        max = width[i];
        if (max == 1)
          break;
      }
    cout << max << "\n";
  }
  return 0;
}
