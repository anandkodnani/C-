#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

struct Node {
  int val;
  Node *left;
  Node *right;
  int height;
};

Node *newNode(int val) {
  Node *node = new Node;
  node->val = val;
  node->right = nullptr;
  node->left = nullptr;
  node->height = 1;
  return node;
}

// Implement height
int height(Node *root) {
  if (!root)
    return 0;
  return root->height;
}

int getBalance(Node *root) {
  if (!root)
    return 0;
  return (height(root->left) - height(root->right));
}

Node *leftRotate(Node *root) {
  Node *newRoot = root->right;
  Node *transfer = newRoot->left;
  newRoot->left = root;
  root->right = transfer;

  root->height = max(height(root->left), height(root->right)) + 1;
  newRoot->height = max(height(root->left), height(root->right)) + 1;
  return newRoot;
}

Node *rightRotate(Node *root) {
  Node *newRoot = root->left;
  Node *transfer = newRoot->right;
  newRoot->right = root;
  root->left = transfer;

  root->height = max(height(root->left), height(root->right)) + 1;
  newRoot->height = max(height(root->left), height(root->right)) + 1;
  return newRoot;
}

// Implement insert.
Node *insert(Node *root, int val) {

  if (!root)
    return newNode(val);

  if (val < root->val)
    root->left = insert(root->left, val);
  else
    root->right = insert(root->right, val);
  // Upto now it is BST.

  // Update height.
  root->height = max(height(root->left), height(root->right)) + 1;
  int balance = getBalance(root);

  // There are 4 cases to handle here.

  // 1. Left-Left case.
  if (balance > 1 && val < root->left->val)
    return rightRotate(root);

  if (balance > 1 && val > root->left->val) {
    root->left = leftRotate(root->left);
    return rightRotate(root);
  }

  if (balance < -1 && val > root->right->val)
    return leftRotate(root);

  if (balance < -1 && val < root->right->val) {
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }

  return root;
}

void preOrder(Node *root) {
  if (!root)
    return;

  cout << "  " << root->val;
  preOrder(root->left);
  preOrder(root->right);
}
/* Drier program to test above function*/
int main()
{
  Node *root = NULL;
 
  /* Constructing tree given in the above figure */
  root = insert(root, 10);
  root = insert(root, 20);
  root = insert(root, 30);
  root = insert(root, 40);
  root = insert(root, 50);
  root = insert(root, 25);
 
  /* The constructed AVL Tree would be
            30
           /  \
         20   40
        /  \     \
       10  25    50
  */
 
  printf("Pre order traversal of the constructed AVL tree is \n");
  preOrder(root);
  cout << "\n\n";
  return 0;
}
