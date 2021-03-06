#include <iostream>
using namespace std;

struct Node {
  int val;
  Node *next;
  Node *arbit;
};

void insertNode(Node **head, int val) {
  Node *node = new Node;
  node->val = val;
  node->next = nullptr;
  node->arbit = nullptr;

  if (!head)
    *head = node;
  else {
    node->next = *head;
    *head = node;
  }
}

void combineMerge(Node **head1, Node **head2, Node **newHead) {
  Node *temp1 = *head1;
  Node *temp2 = *head2;
  while (temp1 || temp2) {
    if (temp1 && temp2 && temp1->val >= temp2->val) {
      insertNode(newHead, temp1->val);
      temp1 = temp1->next;
    } else if (temp1 && temp2 && temp2->val > temp1->val) {
      insertNode(newHead, temp2->val);
      temp2 = temp2->next;
    } else if (temp1 && !temp2) {
      insertNode(newHead, temp1->val);
      temp1 = temp1->next;
    } else if (temp2 && !temp1) {
      insertNode(newHead, temp2->val);
      temp2 = temp2->next;
    } 
  }
}

void mergeSort(Node **head, Node **final) {
  if ((*head)->next == nullptr)
    return;

  Node *tHead = *head;
  Node *fast = tHead;
  Node *slow = tHead;
  Node *prev = nullptr;
  while (fast) {
    prev = slow;
    slow = slow->next;
    fast =  fast->next;
    if (fast)
      fast = fast->next;
    else
      break;
  }

  if (prev)
    prev->next = nullptr;
  // Slow gives the split.
  Node *head1 = tHead;
  Node *head2 = slow;
  mergeSort(&head1, final);
  mergeSort(&head2, final);
  Node *newHead = nullptr;
  combineMerge(&head1, &head2, &newHead);
  final = &newHead;
}


int main() {

  Node *head = nullptr;
  insertNode(&head, 3);
  insertNode(&head, 2);
  insertNode(&head, 10);
  insertNode(&head, 5);
  Node *final = nullptr;
  mergeSort(&head, &final);
  Node *temp = final;
  while (temp) {
    cout << " " << temp->val;
    temp = temp->next;
  }
  return 0;
}
