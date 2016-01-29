#include<iostream>
#include<fstream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<map>
#include<cstdlib>
#include<climits>
#include<queue>
using namespace std;

bool DEBUG = false;
// Create a structure to hold junction information.
struct Junction {
  unsigned seqNum;
  signed long long xcord;
  signed long long  ycord;
  vector<Junction> connections;
};

struct JEdge {
  Junction *first;
  Junction *second;
  signed long long xdist;
  signed long long ydist;
  signed long long weight;
};

vector<Junction * > JVector;
map<unsigned, Junction * > JMap;
map<Junction *, unsigned > RevJMap;

vector<JEdge *> EdgeVector;
map<Junction *, vector<JEdge *> > JGraph;
typedef map<Junction *, vector<JEdge *> >::iterator JGraphIt;

void shortest_path_impl(Junction *src, Junction *dst, signed long long H,
                        signed long long V,
                        map<Junction *, bool> &Visited,
                        map<Junction *, unsigned> &Weights,
                        map<Junction *, Junction *> &Parent) {

  if (src == dst)
    return;      

  queue<Junction *> Q;
  Q.push(src);

  while (!Q.empty()) {
    Junction *Node = Q.front();
    Q.pop();

    for (auto &Edge : JGraph[Node])
      if (!Visited[Edge->second] &&
          (Weights[Edge->second] > Weights[Node] + Edge->weight) ) {
        Weights[Edge->second] = Weights[Node] + Edge->weight;
        Visited[Edge->second] = true;
        Parent[Edge->second] = Node;
        Q.push(Edge->second);
      }
  }
  return;
}

bool shortest_path(Junction *src, Junction *dst, signed long long H,
                   signed long long V) {

  map<Junction *, bool> Visited;
  map<Junction *, unsigned> Weights;
  map<Junction *, Junction *> Parent;
  for (auto &J : JVector) {
    Visited[J] = false;
    Weights[J] = UINT_MAX;
    Parent[J] = nullptr;
  }

  Visited[src] = true;
  Weights[src] = 0;
  shortest_path_impl(src, dst, H, V, Visited, Weights, Parent);

  Junction *first = Parent[dst];
  Junction *second = dst;
  signed long long hor = 0, ver = 0;
  while (first) {
    hor += abs(first->xcord - second->xcord);
    if (hor > H)
      return false;
    ver += abs(first->ycord - second->ycord);
    if (ver > V)
      return false;
    second = first;
    first = Parent[second];
  }
  return true;
}

int main() {
  unsigned long long numPairs = 0;
  //ifstream in;
  //in.open("input.txt");
  // Read the input;
  // Number of junctions
  signed long long N, H, V;
  cin >> N;
  cin >> H;
  cin >> V;
  // Implement the constraints;

  for (unsigned i = 1; i <= N; ++i) {
    Junction *J = new Junction;
    J->seqNum = i;
    signed long long  x,y;
    cin >> x;
    cin >> y;
    J->xcord = x;
    J->ycord = y;
    JVector.push_back(J);
    JMap[i] = J;
    RevJMap[J] = i;
  }

  for (unsigned i = 1; i <= N - 1; ++i) {
    unsigned first, second;
    cin >> first;
    cin >> second;
    Junction *firstJunction = JMap[first];
    Junction *secondJunction = JMap[second];
    JEdge *edge = new JEdge;
    edge->first = firstJunction;
    edge->second = secondJunction;
    edge->xdist = abs(firstJunction->xcord - secondJunction->xcord);
    edge->ydist = abs(firstJunction->ycord - secondJunction->ycord);
    edge->weight = edge->xdist + edge->ydist;
    EdgeVector.push_back(edge);
    JGraph[firstJunction].push_back(edge);
  }
  
  // find the shortest distance between all sets of points.
  for (unsigned i = 1; i <= JVector.size(); ++i) {
    for (unsigned j = i + 1; j <= JVector.size(); ++j) {
      if (!shortest_path(JMap[i], JMap[j], H, V))
        ++numPairs;
    }
  }

  if (DEBUG) {
    cout << "\n\n List of junctions\n\n";
    for (auto &J : JVector) {
      cout << "Junction : " << J->seqNum;
      cout << " " << "x value : " << J->xcord;
      cout << " " << "y value : " << J->ycord;
      cout << "\n";
    }
  }

  cout << "\n\n Num Pairs : " << numPairs;
  in.close();
  return 0;
}
