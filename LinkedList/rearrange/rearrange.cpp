#include <iostream>
using namespace std;

struct Node {
  int val;
  Node *next;
};

void insertNode(Node **head, int val) {
  Node *node = new Node;
  node->val = val;
  node->next = nullptr;

  if (!head)
    *head = node;
  else {
    node->next = *head;
    *head = node;
  }
}

void rearrange(Node *head) {
  Node *end = nullptr;
  Node *temp = head;
  while (temp) {
    end = temp;
    temp = temp->next;
  }
  
}

int main() {
  Node *head = nullptr;
  insertNode(&head, 4);
  insertNode(&head, 3);
  insertNode(&head, 2);
  insertNode(&head, 1);
  
  rearrange(head);
  Node *temp = head;
  while (temp) {
    cout << " " << temp->val;
    temp = temp->next;
  }
  return 0;
}
