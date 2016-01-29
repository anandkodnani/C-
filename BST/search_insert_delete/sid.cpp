#include<iostream>
#include<stdio.h>
using namespace std;

struct Node {
  int key;
  Node *left;
  Node *right;
};

Node *newNode(int key) {
  Node *node = new Node;
  node->key = key;
  node->right = node->left = nullptr;
  return node;
}

Node *insert(Node *root, int key) {
  if (!root)
    root = newNode(key);

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

Node *minValueNode(Node *root) {
  if (!root)
    return nullptr;
  while (root->left != nullptr)
    root = root->left;
  return root;
}

Node *deleteNode(Node *root, int key) {
  if (!root)
    return nullptr;

  if (key < root->key)
    root->left = deleteNode(root->left, key);
  else if (key > root->key)
    root->right = deleteNode(root->right, key);
  else {

  if (root->left == nullptr && root->right == nullptr) {
    delete root;
    return nullptr;
  } else if (root->left == nullptr && root->right) {
    root->key =  root->right->key;
    root->right = deleteNode(root->right, root->right->key);
  } else if (root->right == nullptr && root->left) {
    root->key = root->left->key;
    root->left = deleteNode(root->left, root->left->key);
  } else {
    // get the inorder successor
    Node *succ = minValueNode(root->right);
    root->key = succ->key;
    root->right = deleteNode(root->right, succ->key);
  }
  }
  return root;
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
  Node *root = NULL;
  root = insert(root, 50);
  root = insert(root, 30);
  root = insert(root, 20);
  root = insert(root, 40);
  root = insert(root, 70);
  root = insert(root, 60);
  root = insert(root, 80);
 
  printf("Inorder traversal of the given tree \n");
  inorder(root);
 
  printf("\nDelete 20\n");
  root = deleteNode(root, 20);
  printf("Inorder traversal of the modified tree \n");
  inorder(root);
 
  printf("\nDelete 30\n");
  root = deleteNode(root, 30);
  printf("Inorder traversal of the modified tree \n");
  inorder(root);
 
  printf("\nDelete 50\n");
  root = deleteNode(root, 50);
  printf("Inorder traversal of the modified tree \n");
  inorder(root);
 
  return 0;
}
