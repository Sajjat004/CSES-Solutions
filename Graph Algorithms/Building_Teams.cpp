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
vector<int> color(N, -1);
bool cycle = 0;

void dfs(int u) {
  for (auto v : g[u]) {
    if (color[v] == color[u]) {
      cycle = 1;
      continue;
    }
    if (color[v] != -1) continue;
    color[v] = (color[u] == 1) ? 2 : 1;
    dfs(v);
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
    for (int i = 1; i <= m; ++i) {
      int u, v; cin >> u >> v;
      g[u].pb(v);
      g[v].pb(u);
    }
    for (int i = 1; i <= n; ++i) {
      if (color[i] == -1) {
        color[i] = 1;
        dfs(i);
      }
    }
    if (cycle) cout << "IMPOSSIBLE" << nl;
    else {
      for (int i = 1; i <= n; ++i) cout << color[i] << " ";
      cout << nl;
    }
  }
  return 0;
}
