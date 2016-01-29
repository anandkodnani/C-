#include <iostream>
using namespace std;

struct Node {
  int val;
  Node *left;
  Node *right;
};

Node *newNode(int val) {
  Node *node = new Node;
  node->val = val;
  node->right = nullptr;
  node->left = nullptr;
  return node;
}

Node *RemoveHalfNodes(Node *root) {
  if (!root)
    return nullptr;

  if (!root->left && root->right)
    root = RemoveHalfNodes(root->right);


}

// Driver program
int main(void)
{
  Node *NewRoot=NULL;
  Node *root = newNode(2);
  root->left        = newNode(7);
  root->right       = newNode(5);
  root->left->right = newNode(6);
  root->left->right->left=newNode(1);
  root->left->right->right=newNode(11);
  root->right->right=newNode(9);
  root->right->right->left=newNode(4);
 
  printf("Inorder traversal of given tree \n");
  printInoder(root);
 
  NewRoot = RemoveHalfNodes(root);
 
  printf("\nInorder traversal of the modified tree \n");
  printInoder(NewRoot);
  return 0;
}
