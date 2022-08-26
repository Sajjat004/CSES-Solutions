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

int n, m, k;
vector<pair<int, ll>> g[N];
priority_queue<ll> best[N];

void dijkstra(int src) {
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
  best[src].push(0);
  pq.push({0, src});
  while (!pq.empty()) {
    int u = pq.top().ss;
    ll du = pq.top().ff;
    pq.pop();
    if (du > best[u].top()) continue;
    for (auto x : g[u]) {
      int v = x.ff;
      ll w = x.ss;
      ll temp = w + du;
      if (szof(best[v]) < k) {
        best[v].push(temp);
        pq.push({temp, v});
      } else if (temp < best[v].top()) {
        best[v].pop();
        best[v].push(temp);
        pq.push({temp, v});
      }
    }
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
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i) {
      int u, v; cin >> u >> v;
      ll w; cin >> w;
      g[u].pb({v, w});
    }
    dijkstra(1);
    vll res;
    while(!best[n].empty()) {
      res.pb(best[n].top());
      best[n].pop();
    }
    reverse(all(res));
    for (auto x : res) cout << x << " ";
    cout << nl;
  }
  return 0;
}
