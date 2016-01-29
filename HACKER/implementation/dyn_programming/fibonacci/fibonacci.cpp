#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

class BigInteger {
public:
  BigInteger(string str = "");
  BigInteger operator+ (BigInteger &in);
  BigInteger operator* (BigInteger &in);
  friend std::ostream &operator<< (std::ostream &out, const BigInteger &in);
  vector<int> &getNumber();
  void setNumber(vector<int> &val);
private:
  vector<int> number;
};

BigInteger::BigInteger(string str) {
  transform(str.rbegin(), str.rend(), back_inserter(number),
            [](char c) {return c - '0';});
}

vector<int> &BigInteger::getNumber() {return number;}
void BigInteger::setNumber(vector<int> &val) {
  transform(val.begin(), val.end(), back_inserter(number),
            [](int c) {return c - 0;});  
}

BigInteger BigInteger::operator+ (BigInteger &val) {
  int len = max(val.getNumber().size(), number.size());
  int minLen = min(val.getNumber().size(), number.size());;
  vector<int> other = val.getNumber(); 
  BigInteger Result;

  int carry = 0;
  for (int i = 0; i < len; ++i) {
    int addBit;
    if (i >= minLen && other.size() > number.size())
      addBit = other[i] + carry;
    else if (i >= minLen && other.size() <  number.size())
      addBit = number[i] + carry;
    else if (i < minLen && number.size() > 0 && other.size() > 0)
      addBit = number[i] + other[i] + carry;
    else
      break;

    if (addBit >= 10)
      carry = 1;
    else
      carry = 0;
    Result.getNumber().push_back(addBit % 10);
  }

  if (carry)
    Result.getNumber().push_back(1);

  return Result;
}

BigInteger BigInteger::operator* (BigInteger &val) {
  vector<int> other = val.getNumber(); 
  BigInteger Result;
  int len1 = number.size();
  int len2 = other.size();

  int carry = 0;
  for (int i = 0; i < len1; ++i) {
    BigInteger iter;
    int num1 = number[i];
    int carry = 0;
    if (i > 0)
      iter.getNumber().insert(iter.getNumber().begin(), i, 0);
    for (int j = 0; j < len2; ++j) {
      int mulBit = num1 * other[j] + carry;
      iter.getNumber().push_back(mulBit % 10);
      carry = mulBit / 10;
    }
    if (carry)
      iter.getNumber().push_back(carry);
    Result = Result + iter;
  }
  return Result;
}

std::ostream &operator<< (std::ostream &out,
                          const BigInteger &in) {
  int len = in.number.size();
  for (int i = len - 1; i >= 0; --i)
    out << in.number[i];
  return out;
}

int main() {
  ifstream in("input.txt");
  int first, second, N;
  in >> first >> second >> N;

  BigInteger fib[N];
  fib[0] = BigInteger(to_string(first));
  fib[1] = BigInteger(to_string(second));

  for (int i = 2; i < N; ++i)
    fib[i] = fib[i - 1]*fib[i - 1] + fib[i - 2];

  cout << fib[N - 1] << "\n\n";
  //  BigInteger a("123456789");
  //BigInteger b("11");
  //cout << "\n\n" << a + b;
  return 0;
}
