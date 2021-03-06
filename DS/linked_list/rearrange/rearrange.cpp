#include <iostream>
#include <cstdio>
using namespace std;

struct Node {
  char val;
  Node * next;
};

Node *newNode(char val) {
  Node *node = new Node;
  node->val = val;
  node->next = nullptr;
  return node;
}

Node *insert(Node *head, char val) {
  if (!head)
    return newNode(val);
  Node *node = newNode(val);
  node->next = head;
  head = node;
}

void reverseList(Node **head) {
  Node *prev = nullptr;
  Node *next = nullptr;
  Node *curr = *head;
  while (curr) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  *head = prev;
}

void rearrange(Node *head) {
  
  if (!head)
    return;

  Node *head1 = nullptr;
  Node *head2 = nullptr;

  // Find the middle point.
  Node *slow = head;
  Node *fast = head->next;
  while (fast) {
    fast = fast->next;
    if (fast) {
      slow = slow->next;
      fast = fast->next;
    }
  }

  head1 = head;
  head2 = slow->next;
  //free(slow);
  //free(fast);
  //  fflush();
  // Reverse head2;
  reverseList(&head2);
  Node *temp = head2;
  cout << "\n\ncheck";
  while (temp) {
    //printf("  %d", temp->val);
    cout << "  " << temp->val;
    temp = temp->next;
  }
  cout << "\n\n";
}

int main() {
  Node *head = nullptr;
  head = insert(head, 5);
  head = insert(head, 4);
  head = insert(head, 3);
  head = insert(head, 2);
  head = insert(head, 1);
  rearrange(head);
  free(head);
  return 0;
}
