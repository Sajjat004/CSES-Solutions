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

vi g[N], rg[N];
int level[N];
vi res;
int n;

void dfs(int u) {
  res.pb(u);
  if (u == n) return;
  int l = -1, v;
  for (auto x : g[u]) {
    if (level[x] > l) {
      l = level[x];
      v = x;
    }
  }
  if (l != -1) dfs(v);
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(false); cin.tie(0);
  int test = 1, tc = 0;
  while (test--) {
    int m; cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
      int u, v; cin >> u >> v;
      g[u].pb(v);
      rg[v].pb(u);
    }
    priority_queue<pii> pq;
    pq.push({1, n});
    while (!pq.empty()) {
      int l = pq.top().ff;
      int u = pq.top().ss;
      pq.pop();
      if (level[u] >= l) continue;
      level[u] = l;
      for (auto v : rg[u]) {
        pq.push({l + 1, v});
      }
    }
    dfs(1);
    if (res.back() != n) cout << "IMPOSSIBLE" << nl;
    else {
      cout << szof(res) << nl;
      for (auto x : res) cout << x << " ";
      cout << nl;
    }
  }
  return 0;
}
