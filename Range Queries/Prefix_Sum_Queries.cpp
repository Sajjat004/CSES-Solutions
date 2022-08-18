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

struct node {
  ll sum, prefix;
  node() {
    sum = 0LL;
    prefix = 0LL;
  }
  friend node operator+(const node& a, const node& b) {
    node ret;
    ret.sum = a.sum + b.sum;
    ret.prefix = max(a.prefix, (a.sum + b.prefix));
    return ret;
  }
};

class SegTree {
  vector<node> tree;
  int n;

  void build(int at, int b, int e) {
    if (b == e) {
      tree[at].sum = ar[b];
      tree[at].prefix = max(0, ar[b]);
      return;
    }
    int mid = (b + e) >> 1;
    build(2 * at, b, mid);
    build(2 * at + 1, mid + 1, e);
    tree[at] = tree[2 * at] + tree[2 * at + 1];
  }

  void update(int at, int b, int e, int idx, int val) {
    if (idx > e or idx < b) return;
    if (b == e) {
      tree[at].sum = val;
      tree[at].prefix = max(0, val);
      return;
    }
    int mid = (b + e) >> 1;
    update(2 * at, b, mid, idx, val);
    update(2 * at + 1, mid + 1, e, idx, val);
    tree[at] = tree[2 * at] + tree[2 * at + 1];
  }

  node query(int at, int b, int e, int l, int r) {
    if (r < b or e < l) return node();
    if (l <= b and e <= r) return tree[at];
    int mid = (b + e) >> 1;
    node x = query(2 * at, b, mid, l, r);
    node y = query(2 * at + 1, mid + 1, e, l, r);
    return x + y;
  }

public:
  SegTree(int n) {
    this->n = n;
    tree.resize(4 * (n + 2));
    build(1, 1, n);
  }

  void update(int idx, int val) {
    update(1, 1, n, idx, val);
  }

  node query(int l, int r) {
    return query(1, 1, n, l, r);
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
    SegTree ds(n);
    while (q--) {
      int op; cin >> op;
      if (op == 1) {
        int idx, val;
        cin >> idx >> val;
        ds.update(idx, val);
      } else {
        int l, r; cin >> l >> r;
        node res = ds.query(l, r);
        cout << res.prefix << nl;
      }
    }
  }
  return 0;
}
