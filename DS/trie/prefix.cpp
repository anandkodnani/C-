#include <iostream>
#include <string>
using namespace std;

#define ALPHA 26
// Create a trie node.
struct trie_node {
  char val;
  trie_node *alpha[ALPHA];
  bool end;
};

/*class Trie {
  trie_node *root;

public:
  
  void insert(trie_node *root, string val);
  string longestPrefix(trie_node *root, string word);
  };*/

trie_node *newNode(char val) {
  trie_node *node = new trie_node;
  node->val = val;
  for (int i = 0; i < ALPHA; ++i)
    node->alpha[i] = nullptr;

  node->end = false;
  return node;
}

void insert(trie_node **root, string val) {
  
  if (!(*root)) {
    *root =  newNode('$');
    return;
  }

  trie_node *current = *root;
  for (int i = 0; i < val.length(); ++i) {
    int index = val[i] - 'a';
    if (!current->alpha[index])
      current->alpha[index] = newNode(val[i]);
    current =  current->alpha[index];
  }
  current->end = true;
}

string longestPrefix(trie_node *root, string input) {

  trie_node *curr = root;
  string str = "";
  for (int i = 0; i < input.length(); ++i) {
    int index = input[i] - 'a';
    if (curr->alpha[index]) {
      str += curr->alpha[index]->val;
      curr = curr->alpha[index];
    } else
      return str;
  }
  return str;
}

int main() {

  trie_node *root = nullptr;
  insert(&root, "$");
  insert(&root, "are");
  insert(&root, "area");
  insert(&root, "base");
  insert(&root, "cat");
  insert(&root, "cater");
  insert(&root, "basement");

  string input = "basemexz";
  cout << "\n\nstring caterer : " << longestPrefix(root, input) << "\n\n";
  return 0;
}
