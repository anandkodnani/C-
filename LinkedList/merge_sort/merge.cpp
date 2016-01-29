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

void frontBackSplit(Node **a, Node **b, Node **head) {
  Node *fast = *head;
  Node *slow = *head;
  
  if (!(*head) || (*head)->next == NULL) {
    *a = *head;
    *b = nullptr;
    return;
  }
  
  if (fast)
    fast = fast->next;
  
  while (fast) {
    fast = fast->next;

    if (fast) {
      fast = fast->next;
      slow = slow->next;
    } else
      break;
  }
  *a = *head;
  *b = slow->next;
  slow->next = nullptr;
}

Node *sortedMerge(Node *a, Node *b) {
  Node *result = nullptr;
  Node *front = a;
  Node *back = b;
  
  if (!front && back) {
    return back;
  } else if (front && !back) {
    return front;
  } else {
    if (front->val <= back->val) {
      result = front;
      result->next = sortedMerge(front->next, back);
    } else {
      result = back;
      result->next = sortedMerge(front, back->next);
    }
  }
  return result;
}

void mergeSort(Node **head) {
  Node *a = nullptr;
  Node *b = nullptr;

  if ((*head) == nullptr || (*head)->next == nullptr)
    return;

  frontBackSplit(&a, &b, head);
  
  // Print a.
  Node *temp =  a;
  cout << "\n\n Print a" ;
  while (temp) {
    cout << " " << temp->val;
    temp = temp->next;
  }
  mergeSort(&a);

  temp =  b;
  cout << "\n\n Print b" ;
  while (temp) {
    cout << " " << temp->val;
    temp = temp->next;
  }
  mergeSort(&b);

  *head = sortedMerge(a, b);
}

int main() {

  Node *head = nullptr;
  insertNode(&head, 3);
  insertNode(&head, 2);
  insertNode(&head, 10);
  insertNode(&head, 5);
 
   mergeSort(&head);
  Node *temp = head;
  while (temp) {
    cout << " " << temp->val;
    temp = temp->next;
  }
  return 0;
}
