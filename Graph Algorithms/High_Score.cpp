#include <bits/stdc++.h>
using namespace std;

typedef long long          ll;
typedef long double        ld;
typedef unsigned long long ull;
typedef pair<int, int>     pii;
typedef pair<ll, ll>       pll;
typedef vector<int>        vi;
typedef vector<ll>         vll;

const int N      = (int) 2505;
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

struct eg {
  int u, v;
  ll w;
};

vi g[N];
vi g1[N];
vector<bool> used(N, 0), used1(N, 0);

void dfs(int u) {
  if (used[u]) return;
  used[u] = 1;
  for (auto v : g[u]) dfs(v);
}

void dfs1(int u) {
  if (used1[u]) return;
  used1[u] = 1;
  for (auto v : g1[u]) dfs1(v);
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
    vector<eg> edge;
    for (int i = 0; i < m; ++i) {
      eg x; cin >> x.u >> x.v >> x.w;
      x.w *= -1;
      edge.pb(x);
      g[x.u].pb(x.v);
      g1[x.v].pb(x.u);
    }
    vll dist(n + 2, INF);
    dist[1] = 0;
    bool ok = 0;
    dfs(1);
    dfs1(n);
    for (int i = 1; i <= n; ++i) {
      for (auto x : edge) {
        if (dist[x.u] + x.w < dist[x.v]) {
          dist[x.v] = dist[x.u] + x.w;
          if (i == n and used[x.v] and used1[x.v]) ok = 1;
        }
      }
    }
    if (ok) cout << -1 << nl;
    else cout << -dist[n] << nl;
  }
  return 0;
}
