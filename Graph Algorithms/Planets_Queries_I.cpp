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

int par[N][31];

int jump(int s, int d) {
  for (int k = 30; k >= 0; --k) {
    if (d & (1 << k)) {
      s = par[s][k];
    }
  }
  return s;
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(false); cin.tie(0);
  int test = 1, tc = 0;
  while (test--) {
    int n, q; cin >> n >> q;
    memset(par, -1, sizeof par);
    for (int i = 1; i <= n; ++i) {
      cin >> par[i][0];
    }
    for (int k = 1; k <= 30; ++k) {
      for (int i = 1; i <= n; ++i) {
        if (par[i][k - 1] != -1) par[i][k] = par[par[i][k - 1]][k - 1];
      }
    }
    while (q--) {
      int s, k; cin >> s >> k;
      cout << jump(s, k) << nl;
    }
  }
  return 0;
}
