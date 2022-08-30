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

class Dsu {
  vi par, setSize, rank;
  int numSet, largeSet;
  int n;
  int root(int x) { return par[x] = par[x] == x ? x : root(par[x]); }
public:
  Dsu(int x) {
    n = x;
    par.assign(n + 2, 0);
    setSize.assign(n + 2, 1);
    rank.assign(n + 2, 0);
    numSet = n;
    largeSet = 0;
    for (int i = 1; i <= n; ++i) par[i] = i;
  }

  void merge(int a, int b) {
    int x = root(a), y = root(b);
    if (x == y) return;
    if (rank[x] <= rank[y]) swap(x, y);
    par[y] = x;
    setSize[x] += setSize[y];
    if (rank[x] == rank[y]) rank[x]++;
    largeSet = max(largeSet, setSize[x]);
    numSet--;
  }

  pii query() {
    cout << numSet << " " << largeSet << nl;
  }
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
    Dsu ds(n);
    while (m--) {
      int x, y; cin >> x >> y;
      ds.merge(x, y);
      ds.query();
    }
  }
  return 0;
}
