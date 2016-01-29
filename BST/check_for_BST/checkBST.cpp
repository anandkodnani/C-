#include<iostream>
#include<climits>
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

bool isBSTUtil(Node *root, int min, int max) {

  if (!root)
    return true;
  if (root->key < min || root->key > max)
    return false;

  return isBSTUtil(root->right, root->key + 1, max)
    && isBSTUtil(root->left, min, root->key - 1);
}

bool isBST(Node *root) {
  return isBSTUtil(root, INT_MIN, INT_MAX);
}

/* Driver program to test above functions*/
int main()
{
  struct Node *root = newNode(3);
  root->left        = newNode(2);
  root->right       = newNode(5);
  root->left->left  = newNode(1);
  root->left->right = newNode(4); 
 
  if(isBST(root))
    cout << "Is BST";
  else
    cout << "Not a BST";
     
  getchar();
  return 0;
}  
