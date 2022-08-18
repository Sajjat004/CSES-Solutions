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
 
#ifdef LOCAL
#include "headerFile/debug.h"
#endif
 
class SegTreeLazy {
  vll tree, lazy;
  int n;
 
public:
  SegTreeLazy() {
    tree.resize(4 * mxN, 0LL);
    lazy.resize(4 * mxN, 0LL);
  }
 
  void propagate(int at, int b, int e) {
    if (b == e)
      tree[at] += (lazy[at] * (e - b + 1));
    lazy[2 * at] += lazy[at];
    lazy[2 * at + 1] += lazy[at];
    lazy[at] = 0;
  }
 
  void update(int at, int b, int e, int l, int r, ll val) {
    if (r < b or e < l) return;
    if (l <= b and e <= r) {
      lazy[at] += val;
      return;
    }
    int mid = (b + e) >> 1;
    update(2 * at, b, mid, l, r, val);
    update(2 * at + 1, mid + 1, e, l, r, val);
  }
 
  ll query(int at, int b, int e, int l, int r) {
    if (lazy[at]) propagate(at, b, e);
    if (r < b or e < l) return 0LL;
    if (l <= b and e <= r) return tree[at];
    int mid = (b + e) >> 1;
    ll x = query(2 * at, b, mid, l, r);
    ll y = query(2 * at + 1, mid + 1, e, l, r);
    return x + y;
  }
};
 
int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
#endif
  Fast_IO
  int test = 1, tc = 0;
  while (test--) {
    int n, q; cin >> n >> q;
    vll v(n + 2, 0);
    for (int i = 1; i <= n; ++i) {
      cin >> v[i];
    }
    SegTreeLazy ds;
    while (q--) {
      int op; cin >> op;
      if (op == 1) {
        int l, r;
        ll val; cin >> l >> r >> val;
        ds.update(1, 1, n, l, r, val);
      } else {
        int l; cin >> l;
        // cout << ds.query(1, 1, n, l, l) << nl;
        cout << v[l] + ds.query(1, 1, n, l, l) << nl;
      }
    }
  }
  return 0;
}
