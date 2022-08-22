#include <bits/stdc++.h>
using namespace std;
 
typedef long long           ll;
typedef long double         ld;
typedef unsigned long long  ull;
typedef pair <int, int>     pii;
typedef pair <ll, ll>       pll;
typedef vector <int>        vi;
typedef vector <ll>         vll;
 
const int N       = (int) 2e5 + 5;
const int mxN     = (int) 1e6 + 6;
const int MOD     = (int) 1e9 + 7;
const ll INF      = (ll) 1e18 + 9;
const double EPS  = (double) 1e-9;
 
#define debug(x)  cerr << #x << " = " << x << '\n';
#define all(x)    x.begin(), x.end()
#define szof(x)   (int) x.size()
#define ff        first
#define ss        second
#define pb        push_back
#define mp        make_pair
#define PI        acos(-1.0)
#define nl        '\n'
#define Fast_IO   ios_base::sync_with_stdio(false); cin.tie(0);
 
/*........................ let's try one more time ........................*/

vector<pair<int, ll>> g[N], g1[N];
vll dist1(N, INF), dist2(N, INF);
 
void dijkstra(int src) {
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
  dist1[src] = 0;
  pq.push({0, src});
  while (!pq.empty()) {
    ll du = pq.top().ff;
    int u = pq.top().ss;
    pq.pop();
    if (du != dist1[u]) continue;
    for (auto x : g[u]) {
      int v = x.ff;
      ll w = x.ss;
      if (dist1[v] > (dist1[u] + w)) {
        dist1[v] = dist1[u] + w;
        pq.push({dist1[v], v});
      }
    }
  }
}

void dijkstra1(int src) {
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
  dist2[src] = 0;
  pq.push({0, src});
  while (!pq.empty()) {
    ll du = pq.top().ff;
    int u = pq.top().ss;
    pq.pop();
    if (du != dist2[u]) continue;
    for (auto x : g1[u]) {
      int v = x.ff;
      ll w = x.ss;
      if (dist2[v] > (dist2[u] + w)) {
        dist2[v] = dist2[u] + w;
        pq.push({dist2[v], v});
      }
    }
  }
}
 
int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
#endif
  Fast_IO
  int test = 1, tc = 0;
  while (test--) {
    int n, m; cin >> n >> m;
    vector<pair<ll, pii>> edge;
    for (int i = 0; i < m; ++i) {
      int u, v; cin >> u >> v;
      ll w; cin >> w;
      g[u].pb({v, w});
      g1[v].pb({u, w});
      edge.pb({w, {u, v}});
    }
    dijkstra(1);
    dijkstra1(n);
    ll res = INF;
    for (auto x : edge) {
      ll w = x.ff;
      int u = x.ss.ff, v = x.ss.ss;
      if (dist1[u] != INF and dist2[v] != INF) res = min(res, dist1[u] + w / 2 + dist2[v]);
    }
    cout << res << nl;
  }
  return 0;
}
