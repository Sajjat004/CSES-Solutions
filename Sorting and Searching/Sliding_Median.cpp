#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

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

typedef tree <pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> pbds_set;


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
    for (auto& x : v) cin >> x;
    pbds_set ms;
    for (int i = 0; i < m; ++i) {
      ms.insert({v[i], tc++});
    }
    int pos = (m - 1) / 2;
    cout << (*ms.find_by_order(pos)).ff;
    for (int i = m; i < n; ++i) {
      ms.erase(ms.lower_bound({v[i - m], 0}));
      ms.insert({v[i], tc++});
      cout << " " << (*ms.find_by_order(pos)).ff;
    }
    cout << nl;
  }
  return 0;
}
