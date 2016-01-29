#include <iostream>
#include <cassert>
using namespace std;


class Queue {
  int front;
  int end;
  int size;
  int numElements;
  int *array;
public:
  Queue() {
    front = 0;
    end  = -1;
    size = 100;
    numElements = 0;
    array = new int[size];
  }

  bool isFull() {
    return numElements == size;
  }
  bool isEmpty() {
    return numElements == 0;
  }

  void enqueuue(int val) {
    assert(!isFull());
    ++numElements;
    end = (end + 1) % size;
    array[end] = val;
  }

  int dequeue() {
    assert(!isEnpty());
    int temp = array[front];
    --numElements;
    front = (front + 1) % size;
    return temp;
  }
};
