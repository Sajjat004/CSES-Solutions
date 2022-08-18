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
int table[N][22];
 
void dfs(int u = 1, int par = 0) {
  table[u][0] = par;
  for (int k = 1; k <= 20; ++k) {
    table[u][k] = table[table[u][k - 1]][k - 1];
  }
  for (auto v : g[u]) {
    if (v == par) continue;
    dfs(v, u);
  }
}
 
int jump(int x, int y) {
  for (int k = 20; k >= 0; --k) {
    if (y >= (1 << k)) {
      x = table[x][k];
      y -= (1 << k);
    }
    if (x == 0) return -1;
  }
  return x;
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
    for (int u = 2; u <= n; ++u) {
      int v; cin >> v;
      g[u].pb(v);
      g[v].pb(u);
    }
    dfs();
    while (m--) {
      int x, y; cin >> x >> y;
      cout << jump(x, y) << nl;
    }
  }
  return 0;
}
