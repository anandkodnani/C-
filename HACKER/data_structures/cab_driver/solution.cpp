  Domains   Contests   Leaderboard
  
  anandkodnani  
 
All Domains  Algorithms  Data Structures  Taxicab Driver's Problem
Taxicab Driver's Problem
Authored by gdisastery on Oct 26 2014
Problem
Submissions
Leaderboard
Discussions
Editorial
 Editorial by gdisastery

  Short problem description Given a tree with N nodes, where each node has `(x,y)` coordinates and the distances between two connected nodes is defined by the Manhatten distance. Find the number of unordered pairs `(i,j)` such that it is not possible to drive from `i` to `j` due to the `H` and `V` limits. The limits are `1.N.105` and `0.xi,yi.109`.
It might be easier to count the number of paths that are manageable by the special car and then calculate the wanted number by doing a simple subtraction.
    Use a divide and conquer approach and search for the center `c` of the tree at each recursion (see problem IOI 2011 Race for how and why [1]). For each recursion we need to calculate the number of valid paths which passes through or begins with `c`. Notice that a path from `i` to `j` passes through `c` iff the two nodes are not in the same subtree when the whole tree is rooted at `c`. Now let the horizontal and vertical distance from root `c` to node `i` be `ai` and `bi` respectively. When visiting node `i`, we need to ask (possibly a data structre) the number of nodes `j` NOT being in the `i`'s subtree and having `aj.H.ai` and `bj.V.bi`.
We are not allowed to do this with `O(log2N)` queries since that would be unfeasible for the given constraints. That's why using some 2D data structure would not be good enough for this particular problem.
Instead imagine this subproblem as an offline geometry problem where sweep line and clever fenwick trees are required.
    First let the color of each point be the color of the respective subtree. Then create two points for each node `i`: One data node having xy coorindates `(ai,bi)` and one query node having xy coordinates `(H.ai,V.bi)`.
      Now the problem is, for each query point `(x,y)` having color `c`, how many data points `(x.,y.)` having color `c.` are there fulfilling `x..x` and `y..y` and `c.c.`? If we express those inequations in terms of `ai` and `bi`, we can see that it is the same question as we had before.
        We sort those points by the `x` coordinates (on tie by `y`) and iterate them. We will also maintain some fenwick trees: One global fenwick tree, which we call `G`, and one fenwick tree `Fi` for each color `i`. When meeting a data point, we will add the `y` value to `G` and to the the corresponding `Fi`. When meeting a query point `(x,y,c)` we will ask `G` about the number of points having `y..y` and subtract the number with the answer of the same question when asking `Fc`.
                                                                                                                In total we have `O(N)` points and each point asks one time in `O(logN)` and gets added twice in `O(logN)`. Therfore the total time complexity and the divide and conquer recursion is `O(NlogN)`.
After that we will do the same approach on the trees that are left after removing `c`.
                        By applying the Master Theorem we can see that the total time complexity of the whole algorithm is `O(Nlog2N)`.
Links
                        [1] http://www.ioi2011.or.th/hsc/tasks/solutions/race.pdf
 Set by gdisastery

Problem Setter's code :
//Program: taxi
//Author: gary
//Date: 23/10/2014
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
#define SZ(x) ( (int) (x).size() )
#define dbg(x) cerr << #x << " = " << x << endl;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> pii;
// const int INF = 1e9;
const int MAX_N = 2e5 + 1;
const int POINT = -1;
const int QUERY = +1;

int N;
ll W, H;
int px[MAX_N], py[MAX_N];
set<int> E[MAX_N];

struct fenwick {
  vector<ll> t;
  vector<ll> a;
  void clear(){
    t.clear();
    a.clear();
  }
  void add(ll x){
    a.pb(x);
  }
  void init(){
    sort(a.begin(), a.end());
    t.assign(SZ(a) + 1, 0);
  }
  void update(ll val, ll x){
    int i = lower_bound(a.begin(), a.end(), val) - a.begin();
    for(++i; i < SZ(t); i += i & -i)
      t[i] += x;
  }
  ll query(ll val){
    int i = lower_bound(a.begin(), a.end(), val) - a.begin();
    ll s = 0;
    for(++i; i > 0; i -= i & -i)
      s += t[i];
    return s;
  }
} fwt[MAX_N];

struct point {
  ll x, y;
  int c, e;
  bool operator<(const point& o) const{
    if(x != o.x)
      return x < o.x;
    if(y != o.y)
      return y < o.y;
    return e < o.e;
  }
} pts[MAX_N * 2];
int npts;

// tree size
int ts[MAX_N];

void dfs(int u, int p){
  ts[u] = 1;
  for(int v: E[u])
    if(v != p) {
      dfs(v, u);
      ts[u] += ts[v];
    }
}

int center(int u){
  int p = -1, s = ts[u];
  while(true){
    int n = -1;
    for(int v: E[u]){
      if(v != p && ts[v] * 2 > s){
    n = v;
    break;
      }
    }
    if(n == -1)
      return u;

    p = u;
    u = n;
  }
  return u;
}

void getPoints(int u, int p, ll a, ll b, int c){
  for(int v: E[u]) {
    if(p != v){
      ll na = a + abs(px[u] - px[v]);
      ll nb = b + abs(py[u] - py[v]);
      int nc = (c == -1 ? v : c); // assign new color if not exists
      pts[npts++] = {na, nb, nc, POINT};
      pts[npts++] = {W - na, H - nb, nc, QUERY};
      getPoints(v, u, na, nb, nc);
    }
  }
}

ll geometry(int u){
  ll ret = 0;
  // clear fenwick trees
  fwt[u].clear();
  for(int v: E[u]) fwt[v].clear();

  // First get all points
  npts = 0;
  getPoints(u, -1, 0, 0, -1);
  // And add them to our fenwick trees ... 
  for(int i = 0; i < npts; i++){
    fwt[pts[i].c].add(pts[i].y);
    fwt[u].add(pts[i].y);
  }
  fwt[u].init();
  for(int v: E[u]) fwt[v].init();

  // Now sweep line
  sort(pts, pts + npts);  
  for(int i = 0; i < npts; i++){
    if(pts[i].e == POINT){
      fwt[u].update(pts[i].y, 1);
      fwt[pts[i].c].update(pts[i].y, -1);
    } else {
      ret += fwt[u].query(pts[i].y) + fwt[pts[i].c].query(pts[i].y);
    }
  }
  // We counted too much
  ret /= 2;

  // Now add the paths between root and the nodes.
  for(int i = 0; i < npts; i++) {
    ret += (pts[i].x <= W && pts[i].y <= H && pts[i].e == POINT);
  }
  return ret;
}

ll dq(int u){
  dfs(u, -1);
  u = center(u);
  ll ans = geometry(u);
  for(int v: E[u]) {
    E[v].erase(u);
    ans += dq(v);
  }
  return ans;
}

ll solve(){
  return 1LL * N * (N - 1) / 2 - dq(1);
}

int main(){
  int u, v;
  scanf("%d%lld%lld", &N, &W, &H);
  for(int i = 1; i <= N; i++){
    scanf("%d%d", px + i, py + i);
  }
  for(int i = 0; i < N - 1; i++){
    scanf("%d%d", &u, &v);
    E[u].insert(v);
    E[v].insert(u);
  }
  printf("%lld\n", solve());
  return 0;
}
Statistics
Difficulty: 0.3
Time Complexity: O(nlog2n)
Required Knowledge: tree centroid, divide and conquer
Publish Date: Oct 26 2014
Originally featured in 101 Hack October'14
Join us on IRC at #hackerrank on freenode for hugs or bugs. 
Contest Calendar | Blog | Scoring | Environment | FAQ | About Us | Support | Careers | Privacy Policy | Request a Feature
