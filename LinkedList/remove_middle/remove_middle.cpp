#include <iostream>
using namespace std;

struct Node {
  int x;
  int y;
  Node *next;
};

void insertNode(Node **head, int x, int y) {
  Node *node = new Node;
  node->x = x;
  node->y = y;
  node->next = nullptr;

  if (!(*head))
    *head = node;
  else {
    node->next = *head;
    *head = node;
  }
}

void deleteMid(Node **head) {
  Node *start = *head;
  if (!start || !start->next || !start->next->next)
    return;

  Node *result = *head;
  Node *prev = nullptr;
  bool iter = true;
  while (iter) {
    iter = false;
    start = *head;
  while (start && start->next && start->next->next) {
    if (start->x == start->next->x &&
        start->next->next->x == start->x) {
      iter = true;
      start->next = start->next->next;
    }

    if (start->y == start->next->y &&
        start->next->next->y == start->y) {
      iter = true;
      start->next = start->next->next;
    }

    start = start->next;
  }
  }
}

int main() {
  Node *head = nullptr;
  insertNode(&head, 40,5);
  insertNode(&head, 20,5);
  insertNode(&head, 10,5);
  insertNode(&head, 10,8);
  insertNode(&head, 10,10);
  insertNode(&head, 3,10);
  insertNode(&head, 1,10);
  insertNode(&head, 0,10);
  deleteMid(&head);
  Node *temp = head;
  while (temp) {
    cout << " " << temp->x << " " << temp->y << "\n\n";
    temp = temp->next;
  }
  return 0;
}
