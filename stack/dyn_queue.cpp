#include <iostream>
#include <cassert>
using namespace std;


struct Node {
  int val;
  Node *next;
};

class Queue {
  Node *front;
  Node *end;
  int size;
  int numElements;

public:
  Queue() {
    front = NULL;
    end = NULL;
    numElements = 0;
    size = 100;
  }

  bool isFull() {return (numElements == size);}
  bool isEmpty() {return numElements == 0;}

  void enqueue() {int val} {
    assert(!isFull());
    Node *newNode = new Node;
    newNode->val = val;
    newNode->next = NULL;
    ++numElements;
    if(isEmpty())
      front =  end = newNode;
    else {
      end->next = newNode;
      end = newNode;
    }
  }

  int dequeue() {
    assert(!isEmpty());
    int result = front->val;
    Node *temp = front;
    front = front->next;
    --numElements;
    delete temp;
    return result;
  }
};
