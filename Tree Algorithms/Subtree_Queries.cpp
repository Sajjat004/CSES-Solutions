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
 
vi start(N, 0);
vi nd(N, 0);
int tme = 0;
 
void dfs(int u, int par = -1) {
  start[u] = ++tme;
  for (auto v : g[u]) {
    if (par == v) continue;
    dfs(v, u);
  }
  nd[u] = tme;
}
 
class Bit {
  vll tree;
  int n;
 
public:
  Bit(int n) {
    this->n = n;
    tree.resize(n + 2, 0);
  }
 
  void update(int idx, ll val) {
    while (idx <= n) {
      tree[idx] += val;
      idx += (idx & -idx);
    }
  }
 
  ll query(int idx) {
    ll sum = 0;
    while (idx > 0) {
      sum += tree[idx];
      idx -= (idx & -idx);
    }
    return sum;
  }
};
 
int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
#endif
  Fast_IO
  int test = 1, tc = 0;
  while (test--) {
    int n, q; cin >> n >> q;
    vll values(n + 2, 0);
    for (int i = 1; i <= n; ++i) {
      cin >> values[i];
    }
    for (int i = 1; i < n; ++i) {
      int u, v; cin >> u >> v;
      g[u].pb(v);
      g[v].pb(u);
    }
    dfs(1, -1);
    Bit ds(tme + 2);
    for (int i = 1; i <= n; ++i) {
      ds.update(start[i], values[i]);
    }
    while (q--) {
      int t; cin >> t;
      if (t == 1) {
        int s; cin >> s;
        ll x; cin >> x;
        ds.update(start[s], -values[s]);
        ds.update(start[s], x);
        values[s] = x;
      } else {
        int s; cin >> s;
        cout << ds.query(nd[s]) - ds.query(start[s] - 1) << nl;
      }
    }
  }
  return 0;
}
