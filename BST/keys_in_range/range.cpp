#include<iostream>
using namespace std;

struct Node {
  int key;
  Node *left;
  Node *right;
};

Node *newNode(int key) {
  Node *node = new Node;
  node->key = key;
  node->right = nullptr;
  node->left = nullptr;
}

void Print (Node *root, int k1, int k2) {
  if (!root)
    return;

  if (k1 < root->key)
    Print(root->left, k1, k2);

  if (k1 <= root->key && k2 >= root->key)
    cout << " " << root->key;

  if (k2 > root->key)
    Print(root->right, k1, k2);

}

/* Driver function to test above functions */
int main()
{
  Node *root = new Node;
  int k1 = 10, k2 = 25;
 
  /* Constructing tree given in the above figure */
  root = newNode(20);
  root->left = newNode(8);
  root->right = newNode(22);
  root->left->left = newNode(4);
  root->left->right = newNode(12);
 
  Print(root, k1, k2);
 
  getchar();
  return 0;
}
