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

class Bit {
  vi tree;
  int n;
public:
  Bit(int n) {
    this->n = n;
    tree.assign(n + 2, 0);
  }

  void update(int idx, int val) {
    while (idx <= n) {
      tree[idx] += val;
      idx += (idx & -idx);
    }
  }

  int query(int idx) {
    int sum = 0;
    while (idx > 0) {
      sum += tree[idx];
      idx -= (idx & -idx);
    }
    return sum;
  }

  int query(int l, int r) {
    int sum = 0;
    return (query(r) - query(l - 1));
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
    int n; cin >> n;
    vi v(n + 2, 0);
    for (int i = 1; i <= n; ++i) cin >> v[i];
    Bit ds(n);
    for (int i = 1; i <= n; ++i) {
      ds.update(i, 1);
    }
    for (int i = 1; i <= n; ++i) {
      int x; cin >> x;
      int l = 1, r = n;
      int idx;
      while (l <= r) {
        int mid = (l + r) >> 1;
        if (ds.query(1, mid) == x) {
          idx = mid;
          r = mid - 1;
        } else if (ds.query(1, mid) < x) {
          l = mid + 1;
        } else r = mid - 1;
      }
      cout << v[idx] << " ";
      ds.update(idx, -1);
    }
    cout << nl;
  }
  return 0;
}
