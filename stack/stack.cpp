#include <iostream>
#include <cassert>
using namespace std;

class Stack {
  int size;
  int top;
  int *array;

public:
  Stack() {
    size = 100;
    top =  -1;
    array =  new int[size];
  }
  bool isFull() {return (top == (size -  1));}
  bool isEmpty() {return (top ==  -1);}

  void push(int val) {
    assert(!isFull());
    ++top;
    array[top] = val;
  }

  int pop() {
    assert(!isEmpty());
    int temp = array[top];
    --top;
    return temp;
  }

};

int main() {
  Stack stack;
  stack.push(1);
  stack.push(2);
  stack.push(3);

  cout << "\n\n Stack values \n\n";
  cout << " " << stack.pop();
  cout << " " << stack.pop();
  cout << " " << stack.pop();
  return 0;
}
