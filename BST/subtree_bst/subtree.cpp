#include<iostream>
#include<climits>
#include<cstdio>
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

int largestBSTUtil(Node *root, int &min, int &max, bool &isBST,
                   int maxSize) {

  if (!root) {
    isBST = true;
    return 0;
  }
  int copyMaxSize = maxSize;
  int size_right = largestBSTUtil(root->right, root->key, max, isBST);
  if (size_right > maxSize && isBST)
    maxSize
  int size_left = largestBSTUtil(root->left, min, root->key, istBST);

}

int largetsBST(Node *root) {
  if (!root)
    return 0;
  bool isRightBST = false;
  bool isLeftBST = false;
  int min = INT_MIN;
  int max = INT_MAX;
  int maxSize = 0;
  return largestBSTUtil(root, min, max, isRightBST, isLeftBST);
}

/* Driver program to test above functions*/
int main()
{
  /* Let us construct the following Tree
          50
       /      \
     10        60
    /  \       /  \
   5   20    55    70
            /     /  \
          45     65    80
  */
 
  Node *root = newNode(50);
  root->left        = newNode(10);
  root->right       = newNode(60);
  root->left->left  = newNode(5);
  root->left->right = newNode(20);
  root->right->left  = newNode(55);
  root->right->left->left  = newNode(45);
  root->right->right = newNode(70);
  root->right->right->left = newNode(65);
  root->right->right->right = newNode(80);
 
  /* The complete tree is not BST as 45 is in right subtree of 50.
     The following subtree is the largest BST
        60
      /  \
    55    70
   /     /  \
 45     65    80
  */
  printf(" Size of the largest BST is %d", largestBST(root));
 
  getchar();
  return 0;
}
