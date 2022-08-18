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

int ar[N];

class SegTree {
  vi tree;
  int n;

  void build(int at, int b, int e) {
    if (b == e) {
      tree[at] = ar[b];
      return;
    }
    int mid = (b + e) >> 1;
    build(2 * at, b, mid);
    build(2 * at + 1, mid + 1, e);
    tree[at] = max(tree[2 * at], tree[2 * at + 1]);
  }

public:
  SegTree(int n) {
    this->n = n;
    tree.resize(4 * N);
    build(1, 1, n);
  }

  void update(int at, int b, int e, int idx, int val) {
    if (idx < b or idx > e) return;
    if (b == e) {
      tree[at] -= val;
      return;
    }
    int mid = (b + e) >> 1;
    update(2 * at, b, mid, idx, val);
    update(2 * at + 1, mid + 1, e, idx, val);
    tree[at] = max(tree[2 * at], tree[2 * at + 1]);
  }

  int query(int at, int b, int e, int x) {
    if (b == e) return b;
    int mid = (b + e) >> 1;
    if (tree[2 * at] >= x) return query(2 * at, b, mid, x);
    else return query(2 * at + 1, mid + 1, e, x);
  }

  int check() { return tree[1]; }
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
    SegTree ds(n);
    while (q--) {
      int x; cin >> x;
      if (ds.check() < x) cout << "0 ";
      else {
        int idx = ds.query(1, 1, n, x);
        cout << idx << " ";
        ds.update(1, 1, n, idx, x);
      }
    }
    cout << nl;
  }
  return 0;
}
