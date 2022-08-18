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
const int INF     = (int) 1e9 + 9;
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

vi g[N];
int level[N], cnt[N];
vector<vi> table(N, vi(22, -1));

void dfs(int u = 1, int par = -1, int l = 1) {
  level[u] = l;
  table[u][0] = par;
  for (int k = 1; k <= 20; ++k) {
    if (table[u][k - 1] == -1) break;
    table[u][k] = table[table[u][k - 1]][k - 1];
  }
  for (auto v : g[u]) {
    if (v == par) continue;
    dfs(v, u, l + 1);
  }
}

int lca(int u, int v) {
  if (level[u] < level[v]) swap(u, v);
  for (int k = 20; k >= 0; --k) {
    if ((level[u] - (1 << k)) >= level[v]) u = table[u][k];
  }
  if (u == v) return u;
  for (int k = 20; k >= 0; --k) {
    if (table[u][k] != -1 and table[u][k] != table[v][k]) {
      u = table[u][k];
      v = table[v][k];
    }
  }
  return table[u][0];
}

void dfs1(int u = 1, int par = -1) {
  for (auto v : g[u]) {
    if (par == v) continue;
    dfs1(v, u);
    cnt[u] += cnt[v];
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
    for (int i = 1; i < n; ++i) {
      int u, v; cin >> u >> v;
      g[u].pb(v);
      g[v].pb(u);
    }
    dfs();
    while (m--) {
      int a, b; cin >> a >> b;
      int l = lca(a, b);
      cnt[a]++;
      cnt[b]++;
      cnt[l]--;
      if (table[l][0] != -1) cnt[table[l][0]]--;
    }
    dfs1();
    for (int i = 1; i <= n; ++i) cout << cnt[i] << " ";
    cout << nl;
  }
  return 0;
}
