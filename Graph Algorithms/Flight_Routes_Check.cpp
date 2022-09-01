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

vi used;
vi g[2][N];

void dfs(int u, int r) {
  used[u] = 1;
  for (int v : g[r][u]) {
    if (!used[v]) dfs(v, r);
  }
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
    for (int i = 1; i <= m; ++i) {
      int u, v; cin >> u >> v;
      g[0][u].pb(v);
      g[1][v].pb(u);
    }
    used.assign(n + 2, 0);
    dfs(1, 0);
    for (int i = 1; i <= n; ++i) {
      if (!used[i]) {
        cout << "NO" << nl;
        cout << 1 << " " << i << nl;
        return 0;
      }
    }
    used.assign(n + 2, 0);
    dfs(1, 1);
    for (int i = 1; i <= n; ++i) {
      if (!used[i]) {
        cout << "NO" << nl;
        cout << i << " " << 1 << nl;
        return 0;
      }
    }
    cout << "YES" << nl;
  }
  return 0;
}
