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
map<Junction *, vector<JEdge *> > JInGraph;
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
  bool hit = false;
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

        if (Edge->second == dst) {
          hit = true;
          break;
        }
      }
    if (hit)
      break;
  }
  return;
}

bool shortest_path(Junction *src, Junction *dst, signed long long H,
                   signed long long V) {

  if (abs(src->xcord - dst->xcord) > H)
    return false;
  if (abs(src->ycord - dst->ycord) > V)
    return false;

  map<Junction *, bool> Visited;
  map<Junction *, unsigned> Weights;
  map<Junction *, Junction *> Parent;
  for (auto &J : JVector) {
    Visited[J] = false;
    Weights[J] = INT_MAX;
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
  signed long long numPairs = 0;
  ifstream in;
  in.open("input.txt");
  // Read the input;
  // Number of junctions
  signed long long N, H, V;
  in >> N;
  in >> H;
  in >> V;
  // Implement the constraints;

  for (unsigned i = 1; i <= N; ++i) {
    Junction *J = new Junction;
    J->seqNum = i;
    signed long long  x,y;
    in >> x;
    in >> y;
    J->xcord = x;
    J->ycord = y;
    JVector.push_back(J);
    JMap[i] = J;
    RevJMap[J] = i;
  }

  for (unsigned i = 1; i <= N - 1; ++i) {
    unsigned first, second;
    in >> first;
    in >> second;
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
    JInGraph[secondJunction].push_back(edge);

    JEdge *revEdge =  new JEdge;
    revEdge->first = secondJunction;
    revEdge->second = firstJunction;
    revEdge->xdist = edge->xdist;
    revEdge->ydist = edge->ydist;
    revEdge->weight = edge->weight;
    EdgeVector.push_back(revEdge);
    JGraph[secondJunction].push_back(revEdge);
    JInGraph[firstJunction].push_back(revEdge);
  }
  
  unsigned **dist = new unsigned*[N];
  Junction ***next = new Junction**[N];

  for (unsigned i = 1; i <=N; ++i) {
    dist[i] = new unsigned[N];
    next[i] = new Junction*[N];
  }
  
  for (unsigned i = 1; i <= N; ++i)
    for (unsigned j = 1; j <= N; ++j) {
        dist[i][j] = INT_MAX;
        next[i][j] = nullptr;
    }
  
  for (auto &Edge : EdgeVector) {
    dist[RevJMap[Edge->first]][RevJMap[Edge->second]] = Edge->weight;
    next[RevJMap[Edge->first]][RevJMap[Edge->second]] = Edge->second;

    //dist[RevJMap[Edge->second]][RevJMap[Edge->first]] = Edge->weight;
    //next[RevJMap[Edge->second]][RevJMap[Edge->first]] = Edge->first;
  }


  //  for (unsigned k = 1; k <= N; ++k)
  for (unsigned i = 1; i <= N; ++i) {
   
    for (auto &Edge : JGraph[JMap[i]]) {
      unsigned k = RevJMap[Edge->second];

      /*      for (auto &InEdge : JGraph[JMap[k]]) {
        unsigned j = RevJMap[InEdge->second];
        if (i == j)
        continue;*/
      for (unsigned j = 1; j <= N; ++j) {
        if (dist[i][j] > dist[i][k] + dist[k][j]) {
          //cout << "\n\ni : " << i << " k : " << k << " j : " << j;
          dist[i][j] = dist[i][k] + dist[k][j];
          dist[j][i] = dist[i][j];

          next[i][j] = next[i][k];
          next[j][i] = next[j][k];
        }
      } ///

    }
  }

    for (unsigned i = 1; i <= N; ++i)
      for (unsigned j = i + 1; j <= N; ++j) {
        if (!next[i][j] || !next[j][i])
          continue;
        if (dist[i][j] > H + V) {
          ++numPairs;
          continue;
        }

        Junction *start = nullptr;
        Junction *end = nullptr;
        Junction *nextJ = nullptr;

        if (dist[i][j] > dist[j][i]) {
          start = JMap[j];
          end = JMap[i];
          nextJ = next[j][i];
        } else {
          start = JMap[i];
          end = JMap[j];
          nextJ = next[i][j];
        }
        
        signed long long hor = 0, ver = 0;
        bool unreachable = false;
        while(start != end) {
          hor += abs(start->xcord - nextJ->xcord);
          if (hor > H)
            unreachable = true;
          ver += abs(start->ycord - nextJ->ycord);
          if (ver > V)
            unreachable = true;

          if (unreachable) {
            ++numPairs;
            break;
          }

          start = next[RevJMap[start]][j];
          nextJ = next[RevJMap[start]][j];
        }


      }
  /* // find the shortest distance between all sets of points.
  for (unsigned i = 1; i <= JVector.size(); ++i) {
    for (unsigned j = 1; j <= JVector.size(); ++j) {
      if (!shortest_path(JMap[i], JMap[j], H, V)) {
        ++numPairs;
        if (DEBUG) cout << "\n\n" << numPairs;
      }
    }
    }*/

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
