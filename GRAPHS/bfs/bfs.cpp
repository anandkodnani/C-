#include<iostream>
#include<queue>
#include<set>
#include<list>
#include<map>
using namespace std;
class Graph{
  int V;
  list<int> *adj;
  set<int> nodes;
public:
  Graph(int vertices) {
    this->V = vertices;
    this->adj = new list<int>[vertices];
  }

  void addEdge(int u, int v) {
    this->adj[u].push_back(v);
    this->nodes.insert(u);
    this->nodes.insert(v);
  }

  void bfs(int start) {
    queue<int> Nodes;
    map<int, bool> visited;
    for (auto &v : nodes)
      visited[v] = false;

    visited[start] = true;
    Nodes.push(start);

    while (!Nodes.empty()) {
      int index = Nodes.front();
      Nodes.pop();
      cout << index << " ";
      for (auto &x : this->adj[index])
        if (!visited[x]) {
          visited[x] = true;
          Nodes.push(x);
        }
    }
  }
};

int main () {
  // Create a graph given in the above diagram
  Graph g(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.addEdge(3, 3);
 
  cout << "Following is Breadth First Traversal (starting from vertex 2) \n";
  g.bfs(2);
 
  return 0;
}
