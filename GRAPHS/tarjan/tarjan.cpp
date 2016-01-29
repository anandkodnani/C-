#include <iostream>
using namespace std;

struct Node {
  int v;
  int index;
  int lowlink;
  bool onStack;
};

Node *newNode(int val) {
  Node *node = new Node;
  node->val = val;
  node->index = -1;
  node->lowlink = -1;
  node->onStack = false;
  return node;
}

class Graph {
  int V;
  map<Node *, list<Node *> > adj;
public:

  Graph(int vertices) {
    v = vertices;
  }

  void addEdge(Node *u, Node *v) {
    adj[u].push_back(v);
  }


};
