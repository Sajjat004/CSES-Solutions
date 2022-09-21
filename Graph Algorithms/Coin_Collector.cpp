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
const int INF    = (int) 1e9 + 9;
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

ll value[N];
vll group(N, 0);
vi graph[N];
vll dp(N, -1);

class SSC {
public:
  vi g[N], rg[N];
  vi order, comp, comps;
  vector<bool> used;
  SSC() {
    used.assign(N, 0);
    comp.assign(N, -1);
  }

  void addEdge(int u, int v) {
    g[u].pb(v);
    rg[v].pb(u);
  }

  void dfs(int u) {
    used[u] = 1;
    for (auto v : g[u]) {
      if (!used[v]) dfs(v);
    }
    order.pb(u);
  }

  void dfs1(int u, int x) {
    comp[u] = x;
    for (auto v : rg[u]) {
      if (comp[v] == -1) dfs1(v, x);
    }
  }


  void gen(int n) {
    for (int i = 1; i <= n; ++i) {
      if (!used[i]) dfs(i);
    }
    reverse(all(order));
    for (auto x : order) {
      if (comp[x] == -1) {
        comps.pb(x);
        dfs1(x, x);
      }
    }
  }

} scc;

ll call(int u) {
  if (dp[u] != -1) return dp[u];
  dp[u] = group[u];
  
  for (auto v : graph[u]) {
    dp[u] = max(dp[u], call(v) + group[u]);
  }
  return dp[u];
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
    for (int i = 1; i <= n; ++i) cin >> value[i];
    for (int i = 1; i <= m; ++i) {
      int u, v; cin >> u >> v;
      scc.addEdge(u, v);
    }
    scc.gen(n);
    for (int i = 1; i <= n; ++i) group[scc.comp[i]] += value[i];
    for (int i = 1; i <= n; ++i) {
      for (auto j : scc.g[i]) {
        if (scc.comp[i] != scc.comp[j]) {
          graph[scc.comp[i]].pb(scc.comp[j]);
        }
      }
    }
    ll ans = 0;
    for (auto x : scc.comps) ans = max(ans, call(x));
    cout << ans << nl;
  }
  return 0;
}
