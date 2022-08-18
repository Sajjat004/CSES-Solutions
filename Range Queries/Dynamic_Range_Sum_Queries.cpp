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
 
vll ar(N, 0);
 
class Bit {
  vector<ll> tree;
  int n;
public:
  Bit(int n) {
    this->n = n;
    tree.assign(n + 2, 0);
    for (int i = 1; i <= n; ++i) {
      update(i, ar[i]);
    }
  }
 
  void update(int idx, ll val) {
    while (idx <= n) {
      tree[idx] += val;
      idx += (idx & -idx);
    }
  }
 
  ll query(int idx) {
    ll sum = 0;
    while (idx > 0) {
      sum += tree[idx];
      idx -= (idx & -idx);
    }
    return sum;
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
    for (int i = 1; i <= n; ++i) cin >> ar[i];
    Bit ds(n);
    while (q--) {
      int op; cin >> op;
      if (op == 1) {
        int idx; cin >> idx;
        ll val; cin >> val;
        ds.update(idx, -ar[idx]);
        ds.update(idx, val);
        ar[idx] = val;
      } else {
        int l, r; cin >> l >> r;
        cout << ds.query(r) - ds.query(l - 1) << nl;
      }
    }
  }
  return 0;
}
