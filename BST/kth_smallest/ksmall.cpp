#include<iostream>
#include<vector>
using namespace std;

struct Node {
  int key;
  Node *right;
  Node *left;
  int numLeft;
};

// Create a new node.
Node *newNode(int key) {
  Node *node = new Node;
  node->key = key;
  node->right = nullptr;
  node->left = nullptr;
  node->numLeft = 0;
}

Node *insert(Node *root, int key) {
  if (!root)
    return newNode(key);

  if (key < root->key) {
    ++root->numLeft;
    root->left =  insert(root->left, key);
    //root->left->numLeft = root->numLeft + 1;
  } else if (key > root->key) {
    root->right = insert(root->right, key);
    //root->right->numLeft = root->numLeft + 1;
  }
  return root;
}

Node *createBST(Node *root, vector<int> &elements, unsigned size) {

  for (auto &i : elements)
    if (!root)
      root = insert(root, i);
    else
      insert(root, i);
  return root;
}

void inorderTraversal(Node *root) {
  if (!root)
    return;

  inorderTraversal(root->left);
  cout << "\n num left : " << root->numLeft;
  cout << " key : " << root->key;
  inorderTraversal(root->right);
}

void ksmallest(Node *root, int k, int start, int end) {

  if (!root)
    return;

  int N = (end - start) / 2;

  if (k > N) {
    ksmallest(root->right, k, N + 1, end);
  } else if (k < N){
    ksmallest(root->left, k, start, N);
  } else
    cout << "k smallest " << root->key;
}

int main() {

  // The array.
  vector<int> elements{20, 8, 22, 4, 12, 10, 14};

  Node *root = nullptr;
  // Create a binary search tree.
  root = createBST(root, elements, elements.size());

  //ksmallest(root, 3, 0, elements.size());
  inorderTraversal(root);
}
