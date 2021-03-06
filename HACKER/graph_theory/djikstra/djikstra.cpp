#include <iostream>
#include <climits>
#include <list>
#include <queue>
#include <cstring>
#include <fstream>
#include <map>
using namespace std;

struct Edge {
  int src;
  int dst;
  int weight;
};

class Graph {
private:
  int nodes;
  int edges;
  list<Edge *> Edges;
  map<int, list<Edge *> > adj;
public:
  Graph(int N, int E) {
    nodes = N;
    edges = E;
  }

  void addEdge(Edge *edge) {
    Edges.push_back(edge);
    adj[edge->src].push_back(edge);
  }

  int findMin(int shortest[], bool visited[]) {
    int min = INT_MAX;
    int min_val = INT_MAX;
    for (int i = 1; i < nodes; ++i)
      if (!visited[i] && shortest[i] < min) {
        min = shortest[i];
        min_val = i;
      }
    return min_val;
  }
  
  void computeShortestPath(int start) {
    int shortest[nodes];
    bool visited[nodes];
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < nodes; ++i)
      shortest[i] = INT_MAX - 400;

    shortest[start] = 0;

    for (int i = 1; i < nodes; ++i) {
      int node = findMin(shortest, visited);
      visited[node] = true;
      for (auto *edge : adj[node]) {
        if (!visited[edge->dst] &&
            shortest[edge->dst] > edge->weight + shortest[edge->src]) {
          shortest[edge->dst] = edge->weight + shortest[edge->src];
        }
      }
    }
    
    for (int k = 1; k < nodes; ++k) {
      if (k == start)
        continue;
      if (shortest[k] == INT_MAX - 400)
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
      int src, dst, weight;
      in >> src >> dst >> weight;
      Edge *edge = new Edge;
      edge->src = src;
      edge->dst = dst;
      edge->weight = weight;

      Edge *rev = new Edge;
      rev->src = dst;
      rev->dst = src;
      rev->weight = weight;
      
      G.addEdge(edge);
      G.addEdge(rev);
    }
    int start;
    in >> start;
    G.computeShortestPath(start);
  }
  return 0;
}
