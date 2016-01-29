// Create a Binary search tree with search and insert operations
#include<iostream>
#include<stdlib.h>
using namespace std;

struct Node {
  int key;
  Node *right;
  Node *left;
};

Node *newNode(int key) {
  Node *node = new Node;
  node->key = key;
  node->right = node->left = nullptr;
  return node;
}

// Search BST for value.
Node *searchBST(Node *root, int value) {

  if (root == nullptr)
    return nullptr;

  if (value < root->key)
    return searchBST(root->left, value);
  else if (value > root->key)
    return searchBST(root->right, value);
  return root;
}

// Insert in BST

Node *insert(Node *root, int key) {
  if (!root)
    return newNode(key);

  if (key < root->key)
    root->left = insert(root->left, key);
  else if (key > root->key)
    root->right = insert(root->right, key);
  return root;
}

void inorder(Node *root) {
  if (!root)
    return;

  inorder(root->left);
  cout << root->key << " ";
  inorder(root->right);
}

// Driver Program to test above functions
int main()
{
  /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
         20   40  60   80 */
  Node *root = nullptr;
  root = insert(root, 50);
  insert(root, 30);
  insert(root, 20);
  insert(root, 40);
  insert(root, 70);
  insert(root, 60);
  insert(root, 80);
  
  // print inoder traversal of the BST
  inorder(root);
  
  return 0;
}
