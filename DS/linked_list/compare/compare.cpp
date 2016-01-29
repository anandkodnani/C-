#include <iostream>
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

int compare(Node *str1, Node *str2) {
  int diff = 0;
  while (str1 || str2) {
    
    if (str1 && str2) {
      diff += (str1->val - str2->val);
      str1 = str1->next;
      str2 = str2->next;
    } else if (str1) {
      diff += str1->val;
      str1 = str1->next;
    } else {
      diff += -str2->val;
      str2 = str2->next;
    }
  }

  return diff;
}

int main() {
  Node *str1 = nullptr;
  str1 = insert(str1, 'a');
  str1 = insert(str1, 'k');
  str1 = insert(str1, 'e');
  str1 = insert(str1, 'e');
  str1 = insert(str1, 'g');

  Node *str2 = nullptr;
  str2 = insert(str2, 'b');
  str2 = insert(str2, 'k');
  str2 = insert(str2, 'e');
  str2 = insert(str2, 'e');
  str2 = insert(str2, 'g');

  cout << "\n\n" << compare(str1, str2) << "\n\n";
  return 0;
}
