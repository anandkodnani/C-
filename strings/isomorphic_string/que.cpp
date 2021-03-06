// Lab 10
// Fall 2015

#include <iostream>
#include <cassert>
#include <cstring>
using namespace std;

class DEque
{
private:
  // Structure for nodes
  struct Node {
    char value;    // this deque stores characters
    Node *prev;
    Node *next;
  };
  Node *front;       // Pointer to the first element
  Node *rear;        // Pointer to the last element
    
    
public:
  DEque();
  ~DEque();
  DEque(string);  //define this, it can use a loop
    
  bool isempty();
  void push_front(char value);
  char pop_front();
  void push_back(char value);
  char pop_back();
    
  void printForward();
  void printBackward();
    
  bool palindrome();   //define this recursively: it can call a recursively
  //  defined private function
};


DEque::DEque(string str) {
  front = NULL;
  rear = NULL;
  for (unsigned i = 0; i < str.length(); ++) {
    this.push_back(str[i]);
  }
}

DEque::~DEque() {
  while (!isempty())
    pop_front();
}

bool DEque::isempty() {
  return (front==NULL);
}

void DEque::push_front(char value) {
  Node *newnode = new Node();
  newnode->value = value;
  newnode->prev = NULL;
  newnode->next = NULL;
    
  if (!front) {
    front = newnode;
    rear = newnode;
  } else {
    newnode->next = front;
    front->prev = newnode;
    front = newnode;
  }
}
char DEque::pop_front() {
  assert (!isempty());
    
  char result = front->value;
  Node *temp = front;
  front = front->next;
  if (front)
    front->prev = NULL;
  delete temp;
    
  if (front==NULL)
    rear = NULL;
    
  return result;
}
void DEque::push_back(char value) {
  Node *newnode = new Node();
  newnode->value = value;
  newnode->prev = NULL;
  newnode->next = NULL;
    
  if (!rear) {
    front = newnode;
    rear = newnode;
  } else {
    rear->next = newnode;
    newnode->prev = rear;
    rear = newnode;
  }
}
char DEque::pop_back() {
  assert (!isempty());
    
  char result = rear->value;
  Node *temp = rear;
  rear = rear->prev;
  if (rear)
    rear->next = NULL;
  delete temp;
    
  if (rear==NULL)
    front = NULL;
    
  return result;
}

void DEque::printForward() {
  for (Node *p=front; p; p=p->next)
    cout << p->value << " ";
  cout << endl;
}

void DEque::printBackward() {
  for (Node *p=rear; p; p=p->prev)
    cout << p->value << " ";
  cout << endl;
}

bool DEque::palindrome() {
  if (this->isempty())
    return true;
  
  char a = this.pop_front();
  if (this->isempty())
    return true;
  char b = this.pop_back();
  if (a != b)
    return false;
  palindrome();
}

int main() {

  //add code here to test your palindrome function
  DEque de("aba");
  de.palindrome();
}
