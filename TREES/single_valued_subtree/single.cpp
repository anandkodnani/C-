/*

  Input: root of below tree
              5
             / \
            1   5
           / \   \
          5   5   5
Output: 4

1. get the root store it in a val.

2. recurse through all the subtrees and match it with the val.

3. if it matches, return true else return false. 
*/

#include <iostream>
using namespace std;

struct Node {
  int val;
  Node * left;
  Node *right;
};


Node * newNode(int val) {
  Node *node = new Node;
  node->val = val;
  node->right = nullptr;
  node->left = nullptr;
  return node;
}

int countRecur(Node *root, int val) {
  if (!root)
    return 0;

  if (root->val == val && !root->right && !root->left)
    return 1;

  return 1 + countRecur(root->right, root->val) +
    countRecur(root->left, root->val);
}

int countSingle(Node *root) {
  if (!root)
    return 0;

  int val = root->val;
  return countRecur(root, val);
}

// Driver program to test
int main()
{
  /* Let us construct the below tree
            5
          /   \
        4      5
      /  \      \
      4    4      5 */
  Node* root        = newNode(5);
  root->left        = newNode(4);
  root->right       = newNode(5);
  root->left->left  = newNode(4);
  root->left->right = newNode(4);
  root->right->right = newNode(5);
 
  cout << "Count of Single Valued Subtrees is "
       << countSingle(root);
  return 0;
}
