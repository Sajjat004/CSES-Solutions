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
const ll INF     = (ll) 1e9 + 9;
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

struct dt {
  int u, v;
  ll w;
};

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(false); cin.tie(0);
  int test = 1, tc = 0;
  while (test--) {
    int n, m; cin >> n >> m;
    vector<dt> edge;
    for (int i = 1; i <= m; ++i) {
      dt x;
      cin >> x.u >> x.v >> x.w;
      edge.pb(x);
    }
    int start = 0;
    vector<ll> dist(5005 + 2, INF);
    vi par(5005 + 2, 0);
    for (int i = 1; i <= n; ++i) {
      start = 0;
      for (auto x : edge) {
        if ((dist[x.u] + x.w) < dist[x.v]) {
          dist[x.v] = dist[x.u] + x.w;
          start = x.v;
          par[x.v] = x.u;
        }
      }
    }
    if (!start) cout << "NO" << nl;
    else {
      vi cycle;
      int u = start;
      for (int i = 1; i <= (n + 1); i++) start = par[start];
      u = start;
      while (1) {
        cycle.pb(u);
        if (u == start and szof(cycle) > 1) break;
        u = par[u];
      }
      cout << "YES" << nl;
      reverse(all(cycle));
      for (auto x : cycle) cout << x << " ";
      cout << nl;
    }
  }
  return 0;
}
