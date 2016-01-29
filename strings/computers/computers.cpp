/*
  1. runCustomerSimulation (3, "GACCBDDBAGEE")
  2. Create a map of char to int map<string, int> customer.
  3. Assign 1 if the customer used a computer.
  4. Assign 2 if the customer left without using.
  5. Assign 3 if the customer didn't get any computers.
*/
#include <iostream>
#include <string>
#include <map>
using namespace std;

int runCustomerSimulation(int n, string str) {
  map<char, int> customer;
  for (unsigned i = 0; i < str.length(); ++i) {
    if (str[i] == '\0')
      break;

    map<char, int>::iterator it = customer.find(str[i]);
    if (it != customer.end()) {
      ++n;
    }
    // Check if customer leaves without using.
    else if (str[i + 1] != '\0' && str[i] == str[i + 1]) {
      //customer[str[i]] = 2;
      ++i;
    } else if (n != 0){
      customer[str[i]] = 1;
      n--;
    } else if (n == 0) {
      customer[str[i]] = 3;
    }
    
  }
  int back = 0;
  for (auto it : customer) {
    if (it.second == 3)
      ++back;
  }
  return back;
}

int main() {
  string str = "GACCBGDDBAEE";
  //cout << "\n\n" << runCustomerSimulation(3, str) << "\n\n";
  cout << "\n\n" << runCustomerSimulation(2, "ABBAJJKZKZ") << "\n\n";
  cout << "\n\n" << runCustomerSimulation(3, "GACCBDDBAGEE") << "\n\n";
  cout << "\n\n" << runCustomerSimulation(3, "GACCBDDBAGEE") << "\n\n";
  cout << "\n\n" << runCustomerSimulation(1, "ABCBCA") << "\n\n";
  cout << "\n\n" << runCustomerSimulation(1, "ABCBCADEED") << "\n\n";
  return 0;
}
