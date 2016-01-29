#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Edge {
  int src;
  int dst;
  int weight;
};

bool compare(const Edge *lhs, const Edge *rhs) {
  return (lhs->weight < rhs->weight);
}

class Graph {
  int V;
public :
  vector<Edge *> *adj;
  vector<Edge *> EdgeVector;

  Graph(int vertices) {
    V = vertices;
    adj = new vector<Edge *>[V];
  }

  void addEdge(int src, int dst, int weight) {
    Edge *newEdge = new Edge;
    newEdge->src =  src;
    newEdge->dst = dst;
    newEdge->weight =  weight;
    adj[src].push_back(newEdge);
    EdgeVector.push_back(newEdge);
  }

};

int find(int *parent, int index) {
  if (parent[index] == -1)
    return index;
  return find(parent, parent[index]);
}

void Union(int *parent, int x, int y) {
  int parentx = find(parent, x);
  int parenty = find(parent, y);
  parent[parentx] = parenty;
}

bool isCyclic(vector<Edge *> &MST, int vertices) {
  // Use union find algorithm.
  // 1. Create a parent array.
  int *parent =  new int[vertices];
  for (int i = 0; i < vertices; ++i) {
    parent[i] = -1;
  }

  // 2. Do Union and find for all edges.
  for (auto *edge : MST) {
    int x = find(parent, edge->src);
    int y =  find(parent, edge->dst);
    if (x == y)
      return true;
    Union(parent, x, y);
  }
  return false;
}

void KruskalMST(Graph *graph, int vertices) {
  // 1. Sort all edge in increasing order of edge weight.
  std::sort(graph->EdgeVector.begin(), graph->EdgeVector.end(), compare);
  vector<Edge *> MST;
  int currentEdge = 0;
  MST.push_back(graph->EdgeVector[currentEdge]);
  ++currentEdge;
  
  // 2. Pick up the next edge to see if it forms a cycle.
  for (int i = currentEdge; i < graph->EdgeVector.size(); ++i) {
    MST.push_back(graph->EdgeVector[i]);
    if (isCyclic(MST, vertices))
      MST.pop_back();
  }

  //3. Print all the edge in the MST.
  cout << "\n\n Start MST\n\n";
  for (auto *edge : MST) {
    cout << edge->src << " --------------------- " << edge->dst;
    cout << "   weight = " << edge->weight;
    cout << "\n";
  }
}

int main() {
  Graph *graph = new Graph(4);
  graph->addEdge(0, 1, 10);
  graph->addEdge(0, 2, 6);
  graph->addEdge(0, 3, 5);
  graph->addEdge(1, 3, 15);
  graph->addEdge(2, 3, 4);
  KruskalMST(graph, 4);
  return 0;
}
