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
vi g[N];
vll dp(N, -1);
int n;

ll dfs(int u) {
  if (u == n) return 1;
  if (dp[u] != -1) return dp[u];
  ll ret = 0;
  for (auto v : g[u]) {
    ret += dfs(v);
    ret %= MOD;
  }
  return dp[u] = ret;
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
    }
    cout << dfs(1) << nl;
  }
  return 0;
}
