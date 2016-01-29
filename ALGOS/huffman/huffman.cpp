#include <iostream>
#include <vector>
using namespace std;


struct Node {
  char val;
  int freq;
  int code
  Node *right;
  Node *left;
};

struct MinHeap {
  int size;
  Node *array;
};

Node *createNode(char val, int freq) {
  Node *node = new Node;
  node->val = val;
  node->freq =  freq;
  node->code = -1;
  node->right = NULL;
  node->left = NULL;
  return node;
}

void swap(Node **a, Node **b) {
  Node *temp = *a;
  *a = *b;
  *b = temp;
}

void minHeapify(MinHeap *minHeap, int index) {
  int smallest = index;
  int right = 2 * index + 1;
  int left = 2 * index + 2;
  
  // Check if right exists and is smaller than root;
  if (right < minHeap->size && minHeap->array[right] <
      minHeap->srray[smallest])
    smallest = right;
  
  // Check if left exists and is smaller than root.
  if (left < minHeap->size && minHeap->array[left] <
      minHeap->array[smallest])
    smallest = left;

  if (smallest != index) {
    swap(&minHeap->array[smallest], &minHeap->array[index]);
    minHeapify(minHeap, smallest);
  }
}

MinHeap *buildMinHeap(vector<Node *> nodeVector) {
  MinHeap *minHeap = new MinHeap;
  minHeap->size = nodeVector.size();
  minHeap->array = new Node[nodeVector.size()];

  // populate the array.
  for (int i = 0; i < nodeVector.size(); ++i)
    minHeap->array[i] = nodeVector[i];

  // MinHeapify the arrar.
  for (int i = minHeap->size/2 - 1; i >=0; --i)
    minHeapify(minHeap, i);
  return minHeap;
}

Node *extractMin(MinHeap *minHeap) {
  Node *temp = minHeap->array[0];
  minHeap->array[0] = minHeap->array[minHeap->size -  1];
  --minHeap->size;
  minHeapify(minHeap, 0);
  return temp;
}

void insertMinHeap(Node *node, MinHeap *minHeap) {
  
  ++minHeap->size;
  int i = minHeap->size -  1;
  while (i && node->freq < minHeap->array[(i -  1)/2]->freq) {
    minHeap->array[i] = minHeap->array[(i - 1) / 2];
    i = (i -  1) / 2;
  }
  minHeap->array[i] = node;
}

Node *buildHuffmanTree(vector<Node *> nodeVector) {
  MinHeap *minHeap = buildMinHeap(nodeVector);
  while (minHeap->size > 1) {
    //Extract 2 min nodes.
    Node *left = extractMin(minHeap);
    Node *right = extractMin(minHeap);
    Node *internal = createNode('$', right->freq + left->freq);
    internal->left = left;
    internal->right = right;
    insertMinHeap(internal, minHeap);
  }
  return extractMin(minHeap);  
}

void generateCodes(Node *root) {
  if (!root)
    return;
  if (root->left) {
    root->left->code = 0;
    generateCodes(root->left);
  }
  if (root->right) {
    root->right->code = 1;
    generateCodes(root->right);
  }
}

void printCode(char val, Node *root, string &s) {
  if (!root)
    return;
  
  if (root->left) {
    s += "0";
    printCode(val, root->left)
  }
}

int main() {

  vector<Node *> nodeVector;
  nodevector.push_back(createNode(a, 5));
  nodevector.push_back(createNode(b, 9));
  nodevector.push_back(createNode(c, 12));
  nodevector.push_back(createNode(d, 13));
  nodevector.push_back(createNode(e, 16));
  nodevector.push_back(createNode(f, 45));

  Node *root = buildHuffmanTree(nodeVector);
  generateCodes(root);
  string s = "";
  printCode('a', root, s);
  return 0;
}
