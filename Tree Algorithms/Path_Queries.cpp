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

#ifdef LOCAL
#include "headerFile/debug.h"
#endif

class FenwickTree {
  vll tree;
  int n;
public:
  FenwickTree(int n) {
    this->n = n;
    tree.assign(n + 2, 0);
  }
  void update(int idx, int val) {
    while (idx <= n) {
      tree[idx] += val;
      idx += (idx & -idx);
    }
  }

  ll query(int idx) {
    ll sum = 0;
    while(idx > 0) {
      sum +=tree[idx];
      idx -= (idx & -idx);
    }
    return sum;
  }
};

FenwickTree ds(N);

vi g[N];
int sTime[N], eTime[N];
int cntTime = 0;
int val[N];

void dfs(int u = 1, int par = -1) {
  sTime[u] = ++cntTime;
  for (auto v : g[u]) {
    if (par == v) continue;
    dfs(v, u);
  }
  eTime[u] = cntTime;
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
    for (int i = 1; i <= n; ++i) cin >> val[i];
    for (int i = 1; i < n; ++i) {
      int u, v; cin >> u >> v;
      g[u].pb(v);
      g[v].pb(u);
    }
    dfs();
    for (int i = 1; i <= n; ++i) {
      ds.update(sTime[i], val[i]);
      ds.update(eTime[i] + 1, -val[i]);
    }
    while (m--) {
      int op; cin >> op;
      if (op == 1) {
        int u;
        ll x;
        cin >> u >> x;
        ll dif = x - val[u];
        val[u] = x;
        ds.update(sTime[u], dif);
        ds.update(eTime[u] + 1, -dif);
      } else {
        int u; cin >> u;
        cout << ds.query(sTime[u]) << nl;
      }
    }
  }
  return 0;
}
