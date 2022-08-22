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

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
#endif
  Fast_IO
  int test = 1, tc = 0;
  while (test--) {
    int n, m, q; cin >> n >> m >> q;
    vector<vll> dist(n + 2, vll(n + 2, INF));
    for (int i = 1; i <= n; ++i) dist[i][i] = 0;
    while (m--) {
      int u, v; cin >> u >> v;
      ll w; cin >> w;
      dist[u][v] = min(dist[u][v], w);
      dist[v][u] = min(dist[v][u], w);
    }

    // bellmanford
    for (int k = 1; k <= n; ++k) {
      for (int u = 1; u <= n; ++u) {
        for (int v = 1; v <= n; ++v) {
          if (dist[u][v] > (dist[u][k] + dist[k][v])) {
            dist[u][v] = dist[u][k] + dist[k][v];
          }
        }
      }
    }

    while (q--) {
      int u, v; cin >> u >> v;
      if (dist[u][v] == INF) cout << -1 << nl;
      else cout << dist[u][v] << nl;
    }
  }
  return 0;
}
