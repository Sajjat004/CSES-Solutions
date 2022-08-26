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
bool vis[N];
bool rsFlag[N];
stack<int> rsStack;

bool dfs(int u) {
  vis[u] = 1;
  rsFlag[u] = 1;
  rsStack.push(u);
  for (auto v : g[u]) {
    if (!vis[v] and dfs(v)) return 1;
    if (rsFlag[v]) {
      rsStack.push(v);
      return 1;
    }
  }
  rsStack.pop();
  rsFlag[u] = 0;
  return 0;
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
      g[u].pb(v);
    }

    for (int i = 1; i <= n; ++i) {
      if (!vis[i]) {
        if (dfs(i)) break;
      }
    }

    if (rsStack.empty()) cout << "IMPOSSIBLE" << nl;
    else {
      int temp = rsStack.top();
      rsStack.pop();
      vi res;
      res.push_back(temp);
      while(!rsStack.empty()) {
        res.pb(rsStack.top());
        if (temp == rsStack.top()) break;
        rsStack.pop();
      }
      reverse(all(res));
      cout << szof(res) << nl;
      for (auto x : res) cout << x << " ";
      cout << nl;
    }
  }
  return 0;
}
