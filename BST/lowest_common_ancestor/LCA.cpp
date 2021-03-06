#include<cstdio>
#include<iostream>
using namespace std;

struct Node {
  int key;
  Node *right;
  Node *left;
};

Node *newNode(int key) {
  Node *node = new Node;
  node->key = key;
  node->right = nullptr;
  node->left = nullptr;
}

Node *lca(Node *root, int n1, int n2) {

  if (!root)
    return nullptr;

 if (n1 < root->key && n2 < root->key)
    return lca(root->left, n1, n2);
  if (n1 > root->key && n2 > root->key)
    return lca(root->right, n1, n2);

  return root;
}



/* Driver program to test mirror() */
int main()
{
  // Let us construct the BST shown in the above figure
  Node *root        = newNode(20);
  root->left               = newNode(8);
  root->right              = newNode(22);
  root->left->left         = newNode(4);
  root->left->right        = newNode(12);
  root->left->right->left  = newNode(10);
  root->left->right->right = newNode(14);
 
  int n1 = 10, n2 = 14;
  Node *t = lca(root, n1, n2);
  printf("LCA of %d and %d is %d \n", n1, n2, t->key);
 
  n1 = 14, n2 = 8;
  t = lca(root, n1, n2);
  printf("LCA of %d and %d is %d \n", n1, n2, t->key);
 
  n1 = 10, n2 = 22;
  t = lca(root, n1, n2);
  printf("LCA of %d and %d is %d \n", n1, n2, t->key);
 
  getchar();
  return 0;
}
