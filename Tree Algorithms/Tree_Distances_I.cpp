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

int src1, src2, cnt2;
vi g[N];

void dfs(int u, int level, int par = -1) {
  if (level > cnt2) {
    cnt2 = level;
    src2 = u;
  }
  for (auto v : g[u]) {
    if (v == par) continue;
    dfs(v, level + 1, u);
  }
}

void dfs1(int u, int par, vector<int>& d) {
  for (auto v : g[u]) {
    if (v == par) continue;
    d[v] = d[u] + 1;
    dfs1(v, u, d);
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
    int n; cin >> n;
    for (int i = 1; i < n; ++i) {
      int u, v; cin >> u >> v;
      g[u].pb(v);
      g[v].pb(u);
    }
    dfs(1, 0, -1);
    src1 = src2;
    cnt2 = 0;
    dfs(src1, 0, -1);
    vector<int> dist1(n + 2, 0), dist2(n + 2, 0);
    dfs1(src1, -1, dist1);
    dfs1(src2, -1, dist2);
    for (int i = 1; i <= n; ++i) cout << max(dist1[i], dist2[i]) << " ";
    cout << nl;
  }
  return 0;
}
