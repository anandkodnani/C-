#include<iostream>
using namespace std;

struct Node {
  int key;
  Node *left;
  Node *right;
};

Node *newNode(int key) {
  Node *node =  new Node;
  node->key = key;
  node->right = node->left = nullptr;
  return node;
}

void insert(Node *root, int key) {
  if (!root)
    root = newNode(key);
  if (key < root->key)
    root = insert(root->left, key);
  else if (key > root->key)
    root = insert(root->right, key);
  return root;
}

Node *searchBST(Node *root, int key, Node *search) {
  if (!root)
    return nullptr;
  if (key < root->key)
    searchBST(root->left, key);
  else if (key > root->key)
    searchBST(root->right, key);
  search = root;
}

Node *maxValueNode(Node *root, int key) {
  Node *current = root;
  while (current->right != nullptr) {
    current = current->right;
  }
  return current;
}

Node *minValueNode(Node *root, int key) {
  Node *current = root;
  while (current->left != nullptr) {
    current = current->left;
  }
  return current;
}

void findPredSucc(Node *root, Node *pred, Node *succ, int key) {

  if (!root)
    return;

  // Search the BST
  Node *node = nullptr;
  searchBST(root, key, node);

  //if (!node)
  //return;

  // Calculate inorder predecessor
  // Max of left subtree.
  Node *pred = maxValueNode(node->left, key);
  // Min of right subtree.
  Node *succ = minValueNode(node->right, key);
}
// Driver program to test above function
int main()
{
  int key = 65;    //Key to be searched in BST
 
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
 
 
  Node* pre = NULL, *suc = NULL;
 
  findPreSuc(root, pre, suc, key);
  if (pre != NULL)
    cout << "Predecessor is " << pre->key << endl;
  else
    cout << "No Predecessor";
 
  if (suc != NULL)
    cout << "Successor is " << suc->key;
  else
    cout << "No Successor";
  return 0;
}
