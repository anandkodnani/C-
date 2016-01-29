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
  node->right =nullptr;
  node->left = nullptr;
  return node;
}

Node *insert(Node *root, int key) {
  if (!root)
    return newNode(key);

  if (key > root->key)
    root->right = insert(root->right, key);
  else if (key < root->key)
    root->left = insert(root->left, key);
  return root;
}

void postOrder(Node *root, int &k, int &count) {
  if (!root)
    return;


  postOrder(root->right, k, count);
  ++count;
  if (count == k) {
    cout << "kth largest : " << root->key;
    return;
  }
  postOrder(root->left, k, count);
}

void kthLargest(Node *root, int k) {
  int count = 0;
  postOrder(root, k, count);
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
  insert(root, 30);
  insert(root, 20);
  insert(root, 40);
  insert(root, 70);
  insert(root, 60);
  insert(root, 80);
 
  int c = 0;
  for (int k=1; k<=7; k++)
    kthLargest(root, k);
 
  return 0;
}
