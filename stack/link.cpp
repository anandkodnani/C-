#include <iostream>
#include <cassert>
using namespace std;

struct Node {
  int val;
  Node *next;
};

class Stack {
  Node *head;
public:
  Stack() { head = NULL;}
  bool isFull() {return false;}
  bool isEmpty() {return (head == NULL);}
  
  void push(int num) {
    assert(!isFull());
    Node *node = new Node;
    node->val = num;
    node->next = head;
    head = node;
  }

  int pop() {
    assert(!isEmpty());
    int result = head->val;
    Node *temp = head;
    head = head->next;
    delete temp;
    return result;
  }
  
};
