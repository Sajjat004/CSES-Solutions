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

multiset<int> mset;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
#endif
  Fast_IO
  int test = 1, tc = 0;
  while (test--) {
    int n, m; cin >> n >> m;
    vi v(n, 0);
    for (int i = 0; i < n; ++i) {
      int x; cin >> x;
      mset.insert(x);
    }
    vi res(m + 2, -1);
    for (int i = 0; i < m; ++i) {
      int x; cin >> x;
      auto it = mset.upper_bound(x);
      if (it != mset.begin()) {
        it--;
        res[i] = *it;
        mset.erase(it);
      }
    }
    for (int i = 0; i < m; ++i) cout << res[i] << nl;
  }
  return 0;
}
