#include <iostream>
using namespace std;

struct Node {
  int val;
  Node *next;
};

void insertNode(Node **head, int val) {
  Node *node = new Node;
  node->val =  val;
  node->next = nullptr;
  
  if (!(*head))
    *head = node;
  else {
    node->next = *head;
    *head = node;
  }
}

void insertSort(Node **head) {
  
  Node *x = *head;
  Node *y = *head;
  if (!(*head) || (*head)->next == nullptr)
    return;

  while (x) {
    y = x;
    while (y && y->next) {
      if (y->val > y->next->val) {
        int temp = y->val;
        y->val =  y->next->val;
        y->next->val = temp;
      }
      y = y->next;
    }
    x = x->next;
  }
}

int main() {
  Node *head = nullptr;
  insertNode(&head, 5);
  insertNode(&head, 20);
  insertNode(&head, 4);
  insertNode(&head, 3);
  insertNode(&head, 30);
  insertSort(&head);
  Node *temp = head;
  while (temp) {
    cout << " " << temp->val;
    temp = temp->next;
  }
  return 0;
}
