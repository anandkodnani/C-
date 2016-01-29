#include <iostream>
#include <climits>
#include <list>
#include <queue>
#include <cstring>
#include <fstream>
using namespace std;

class Graph {
private:
  int nodes;
  int edges;
  list<int> *adj;

public:
  Graph(int N, int E) {
    nodes = N;
    edges = E;
    adj = new list<int>[N];
  }

  void addEdge(int src, int dst) {
    adj[src].push_back(dst);
    adj[dst].push_back(src);
  }

  void computeShortestPath(int start) {
    int shortest[nodes];
    bool visited[nodes];
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < nodes; ++i)
      shortest[i] = INT_MAX;

    shortest[start] = 0;
    queue<int> bfs;
    bfs.push(start);
    visited[start] = true;
    while (!bfs.empty()) {
      int node = bfs.front();
      bfs.pop();
      for (auto &x : adj[node]) {
        if (visited[x])
          continue;
        bfs.push(x);
        visited[x] = true;
        if (shortest[x] > 6 + shortest[node])
          shortest[x] = 6 + shortest[node];
      }
    }
    for (int k = 1; k < nodes; ++k) {
      if (shortest[k] == 0)
        continue;
      if (shortest[k] == INT_MAX)
        cout << "-1 ";
      else
        cout << shortest[k] << " ";
    }
    cout << "\n";
  }

};


int main() {
  ifstream in("input1.txt");
  int numTestCase;
  in >> numTestCase;
  
  for (int i = 0; i < numTestCase; ++i) {
    int N, M;
    in >> N;
    in >> M;
    Graph G(N + 1, M);
    for (int j = 0; j < M; ++j) {
      int src, dst;
      in >> src >> dst;
      G.addEdge(src, dst);
    }
    int start;
    in >> start;
    G.computeShortestPath(start);
  }
  return 0;
}
