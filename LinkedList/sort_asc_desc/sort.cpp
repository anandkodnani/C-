#include <iostream>
using namespace std;

struct Node {
  int val;
  Node *next;
};

Node *insertNode(Node *head, int val) {
  Node *node = new Node;
  node->val = val;
  node->next = nullptr;

  if (!head)
    head = node;
  else {
    node->next = head;
    head = node;
  }
  return head;
}

void sortList(Node *head) {
  Node *ascHead = nullptr;
  Node *prev = nullptr;
  Node *descHead = nullptr;
  Node *start = head;
  while (start) {
    ascHead = insertNode(ascHead, start->val);
    start = start->next;
    if (!start)
      break;
    descHead = insertNode(descHead, start->val);
    start = start->next;
  }
  // Reverse descHead.
  start = descHead;
  prev = nullptr;
  Node *next = nullptr;
  while (descHead) {
    next = descHead->next;
    descHead->next = prev;
    prev = descHead;
    descHead = next;
  }
  descHead = prev;

  // print descHead.
  /*Node *temp = descHead;
  while (temp) {
    cout << "  " << temp->val;
    temp = temp->next;
    }*/
  next = nullptr;
  prev = nullptr;
  Node *sortHead = nullptr;
  while (ascHead || descHead) {
    if (ascHead && descHead && ascHead->val <= descHead->val) {
      sortHead = insertNode(sortHead, ascHead->val);
      ascHead = ascHead->next;
    } else if (ascHead && descHead && ascHead->val > descHead->val) {
      sortHead = insertNode(sortHead, descHead->val);
      descHead = descHead->next;
    } else if (!ascHead && descHead) {
      sortHead = insertNode(sortHead, descHead->val);
      descHead = descHead->next;
    } else if (!descHead && ascHead) {
      sortHead = insertNode(sortHead, ascHead->val);
      ascHead = ascHead->next;
    }
  }

  // print sortHead list
  Node *temp = sortHead;
  while (temp) {
    cout << " " << temp->val;
    temp = temp->next;
  }
}

int main() {
  Node *head = nullptr;
  head = insertNode(head, 10);
  head = insertNode(head, 40);
  head = insertNode(head, 53);
  head = insertNode(head, 30);
  head = insertNode(head, 67);
  head = insertNode(head, 12);
  head = insertNode(head, 89);

  sortList(head);  
  return 0;
}
