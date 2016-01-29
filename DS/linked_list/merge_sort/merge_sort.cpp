#include <iostream>
#include <cstdio>
using namespace std;

struct Node {
  int val;
  Node *prev;
  Node *next;
};

Node *newNode(int val) {
  Node *node = new Node;
  node->val = val;
  node->prev = nullptr;
  node->next = nullptr;
  return node;
}

Node *insert(Node *head, int val) {
  if (!head)
    return newNode(val);
  Node *node = newNode(val);

  node->next = head;
  head->prev = node;
  head = node;
  return head;
}

void splitList(Node **head, Node **head1, Node **head2) {
  
  if (!(*head) || (*head)->next == nullptr)
    return;

  // Find the mid point.
  Node *slow = *head;
  Node *fast = (*head)->next;

  while (fast) {
    fast = fast->next;
    if (fast) {
      slow = slow->next;
      fast = fast->next;
    }
  }
  *head1 = *head;
  *head2 = slow->next;
  slow->next = nullptr;
  (*head2)->prev = nullptr;
}

void merge(Node **head, Node **head1, Node **head2) {
  Node *curr = newNode(-1);
  Node *list1 = *head1;
  Node *list2 = *head2;
  Node *temp = nullptr;
  Node *start = curr;
  while (list1 || list2) {
    if (list1 && list2) {
      if (list1->val <= list2->val) {
        curr->next = list1;
        list1->prev = curr;
        curr = curr->next;
        list1 = list1->next;
      } else {
        curr->next = list2;
        list2->prev = curr;
        curr = curr->next;
        list2 = list2->next;
      }
    } else if(list1) {
        curr->next = list1;
        list1->prev = curr;
        curr = curr->next;
        list1 = list1->next;
    } else {
        curr->next = list2;
        list2->prev = curr;
        curr = curr->next;
        list2 = list2->next;
    }
  }

  // Reverse the list
  Node *temp = curr;
  while (temp && temp->prev) {
    temp = temp->prev;
  }

  *head = temp->next;
}

void sort(Node **head) {

  if (!(*head) || (*head)->next == nullptr)
    return;

  // Split the list.
  Node *head1 = nullptr;
  Node *head2 = nullptr;
  splitList(head, &head1, &head2);
  sort(&head1);
  sort(&head2);
  merge(head, &head1, &head2);
  Node *curr = *head;
  printf("\n\n");
  while (curr) {
    printf("  %d", curr->val);
    curr = curr->next;
  }
}

int main() {
  Node *head = nullptr;
  head = insert(head, 5);
  head = insert(head, 20);
  head = insert(head, 4);
  head = insert(head, 3);
  head = insert(head, 30);
  head = insert(head, 10);
  sort(&head);
  return 0;
}
