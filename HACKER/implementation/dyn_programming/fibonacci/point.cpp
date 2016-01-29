#include <iostream>
using namespace std;


class Point {
public:
  Point() {
    x = 0;
    y = 0;
  }

  Point(int a, int b) {
    x = a;
    y = b;
  }

  Point operator++ () {
    this->x += 2;
    this->y += 2;
    return *this;
  }

  void print() {
    cout << x << "\n";
    cout << y << "\n";
  }

  Point(const Point &other) {
    x = other.x;
    y = other.y;
  }

private:
  int x, y;
};


int main() {
  Point a(1, 2);
  ++a;
  Point b(a);
  a.print();
  b.print();

  //  cout << a;
  return 0;
}

return sqrt(a*a + b*b);
