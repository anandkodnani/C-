#include <iostream>
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
  node->left = nullptr;
  node->right = nullptr;
  node->height = 1;
  return node;
}

Node *leftRotate(Node *root) {
  if (!root->right)
    return nullptr;

  Node *x = root->right;
  Node *tree = x->left;
  x->left = root;
  root->right = tree;
  return x;
}

Node *rightRotate(Node *root) {
  if (!root->left)
    return nullptr;

  Node *x = root->left;
  Node *tree = x->right;

  x->right = root;
  root->left = tree;
  return x;
}

Node *search(Node *root, int val) {
  if (!root || root->val == val)
    return root;

  if (root->val > val) {
    if (!root->left)
      return nullptr;

    // When you have a left.
    if (val < root->left->val) {
      // move root->left->left to root.
      root->left->left = search(root->left->left, val);
      // right rotate root.
      ritghtRotate(root);
    } else if (val > root->left->val) {
      // move root->left->right to root.
      root->left->right = search(root->left->right, val);
      if (root->left->right)
        leftRotate(root->left);
    }
    return (root->left) ? rightRotate(root) : nullptr;
  } else {

    if (!root->right)
      return root;

    if (val > root->right->val) {
      // right right case
      root->right->right = search(root->right->right, val);
      leftRotate(root);
    } else if (val < root->right->key){
      // right left case.
      root->right->left = search(root->right->left, val);
      // right rotate root->right.
      if (root->right->left)
        rightRotate(root->right);
    }

    return (root->right) ? leftRotate(root) : nullptr;
  }
}
/* Drier program to test above function*/
int main()
{
  Node *root = newNode(100);
  root->left = newNode(50);
  root->right = newNode(200);
  root->left->left = newNode(40);
  root->left->left->left = newNode(30);
  root->left->left->left->left = newNode(20);
 
  root = search(root, 20);
  printf("Preorder traversal of the modified Splay tree is \n");
  preOrder(root);
  return 0;
}
