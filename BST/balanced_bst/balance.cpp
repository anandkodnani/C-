#include<iostream>
#include<cstdio>
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

Node *sortedArrayToBST(int *arr, int start, int end) {

  if (start > end)
    return nullptr;
  int middle = (start + end) / 2;
  Node *root = newNode(arr[middle]);
  root->left = sortedArrayToBST(arr, start, middle -  1);
  root->right = sortedArrayToBST(arr, middle + 1, end);

  return root;
}

void preOrder(Node *root) {
  if (!root)
    return;

  cout << " " << root->key;
  preOrder(root->left);
  preOrder(root->right);
}

/* Driver program to test above functions */
int main()
{
  int arr[] = {1, 2, 3, 4, 5, 6, 7};
  int n = sizeof(arr)/sizeof(arr[0]);
 
  /* Convert List to BST */
  Node *root = sortedArrayToBST(arr, 0, n-1);
  printf("\n PreOrder Traversal of constructed BST ");
  preOrder(root);
 
  return 0;
}
