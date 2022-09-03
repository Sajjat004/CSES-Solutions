#include <bits/stdc++.h>
using namespace std;

typedef long long          ll;
typedef long double        ld;
typedef unsigned long long ull;
typedef pair<int, int>     pii;
typedef pair<ll, ll>       pll;
typedef vector<int>        vi;
typedef vector<ll>         vll;

const int N      = (int) 2e5 + 5;
const int mxN    = (int) 1e6 + 6;
const int MOD    = (int) 1e9 + 7;
const ll INF     = (ll) 1e18 + 9;
const double EPS = (double) 1e-9;

#define all(x)   x.begin(), x.end()
#define szof(x)  (int) x.size()
#define ff       first
#define ss       second
#define pb       push_back
#define nl       '\n'
#define PI       acos(-1.0)
#define debug(x) cerr << #x << " = " << x << '\n';

/*................. let's try one more time .................*/

vector<pair<int, ll>> g[N];
ll dist[N], num[N], minf[N], maxf[N];

void dijkstra(int src, int n) {
  for (int i = 1; i <= n; ++i) dist[i] = INF;
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
  pq.push({0, src});
  dist[src] = 0;
  num[src] = 1;
  while (!pq.empty()) {
    int u = pq.top().ss;
    ll du = pq.top().ff;
    pq.pop();
    if (du != dist[u]) continue;
    for (auto x : g[u]) {
      int v = x.ff;
      ll w = x.ss;
      if (dist[v] == (dist[u] + w)) {
        num[v] = (num[v] + num[u]) % MOD;
        minf[v] = min(minf[v], minf[u] + 1);
        maxf[v] = max(maxf[v], maxf[u] + 1);
      } else if (dist[v] > (dist[u] + w)) {
        dist[v] = dist[u] + w;
        num[v] = num[u];
        num[v] %= MOD;
        minf[v] = minf[u] + 1;
        maxf[v] = maxf[u] + 1;
        pq.push({dist[v], v});
      }
    }
  }
}



int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(false); cin.tie(0);
  int test = 1, tc = 0;
  while (test--) {
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; ++i) {
      int u, v; cin >> u >> v;
      ll w; cin >> w;
      g[u].pb({v, w});
    }
    dijkstra(1, n);
    cout << dist[n] << " " << num[n] % MOD << " " << minf[n] << " " << maxf[n] << nl;
  }
  return 0;
}
