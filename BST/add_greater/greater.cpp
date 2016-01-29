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


void addGreater(Node *root, int &addVal) {
  if (!root)
    return;

  addGreater(root->right, addVal);
  addVal += root->key;
  root->key = addVal;
  addGreater(root->left, addVal);
}

void inorder(Node *root) {
  if (!root)
    return;

  inorder(root->left);
  cout << " " << root->key;
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
  Node *root = NULL;
  root = insert(root, 50);
  insert(root, 30);
  insert(root, 20);
  insert(root, 40);
  insert(root, 70);
  insert(root, 60);
  insert(root, 80);
 
  int addVal = 0;
  addGreater(root, addVal);
 
  // print inoder tarversal of the modified BST
  inorder(root);
 
  return 0;
}
