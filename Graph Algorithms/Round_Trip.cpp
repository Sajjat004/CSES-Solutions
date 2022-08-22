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
vector<bool> used(N, 0);
int start = -1;

void dfs(int u, int par = -1) {
  if (used[u]) {
    start = u;
    return;
  }
  used[u] = 1;
  for (auto v : g[u]) {
    if (v == par) continue;
    dfs(v, u);
  }
}

vi res;

bool dfs1(int u, int par = -1) {
  if (used[u] and u == start) {
    start = -3;
    res.pb(u);
    return 1;
  } else if (used[u]) return 0;
  used[u] = 1;
  bool done = 0;
  for (auto v : g[u]) {
    if (v == par) continue;
    done |= dfs1(v, u);
  }
  if (done) res.pb(u);
  return done;
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
    for (int i = 0; i < m; ++i) {
      int u, v; cin >> u >> v;
      g[u].pb(v);
      g[v].pb(u);
    }
    for (int i = 1; i <= n; ++i) {
      if (!used[i]) {
        dfs(i);
        if (start != -1) break;
      }
    }
    if (start == -1) cout << "IMPOSSIBLE" << nl;
    else {
      for (int i = 0; i <= n; ++i) used[i] = 0;
      dfs1(start);
    }
    cout << szof(res) << nl;
    for (auto x : res) cout << x << " ";
    cout << nl;
  }
  return 0;
}
