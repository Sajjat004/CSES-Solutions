#include <bits/stdc++.h>
using namespace std;

struct MaxOp { template <typename T> T operator()(T& a, T& b) { return max(a, b); } };
struct MinOp { template <typename T> T operator()(T& a, T& b) { return min(a, b); } };
struct SumOp { template <typename T> T operator()(T& a, T& b) { return a + b; } };

template<typename T, class Func>
struct SegTree {
  Func op;
  int nil;
  int n;
  vector<T> tree;

  void build(int nd, int b, int e, vector<T>& a) {
    if (b == e) {
      tree[nd] = a[b];
      return;
    }
    int mid = (b + e) >> 1;
    build(nd << 1, b, mid, a);
    build(nd << 1 | 1, mid + 1, e, a);
    tree[nd] = op(tree[nd << 1], tree[nd << 1 | 1]);
  }

  void update(int nd, int b, int e, int idx, T val) {
    if (e < idx || idx < b) return;
    if (b == e) {
      tree[nd] = val;
      return;
    }
    int mid = (b + e) >> 1;
    update(nd << 1, b, mid, idx, val);
    update(nd << 1 | 1, mid + 1, e, idx, val);
    tree[nd] = op(tree[nd << 1], tree[nd << 1 | 1]);
  }

  T query(int nd, int b, int e, int l, int r) {
    if (r < b || e < l) return nil;
    if (l <= b && e <= r) return tree[nd];
    int mid = (b + e) >> 1;
    T x = query(nd << 1, b, mid, l, r);
    T y = query(nd << 1 | 1, mid + 1, e, l, r);
    return op(x, y);
  }

  SegTree(int _n, int _nil) : n(_n), nil(_nil), tree(4 * n, _nil) {}
  void build(vector<T>& a) { build(1, 1, n, a); } // array is 1-indexed
  void update(int idx, T val) { update(1, 1, n, idx, val); }
  T query(int l, int r) { return query(1, 1, n, l, r); }
};

void run() {
  int n, q; cin >> n >> q;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];

  SegTree<int, MinOp> seg1(n, INT_MAX);
  SegTree<int, MinOp> seg2(n, INT_MAX);

  for (int i = 1; i <= n; i++) {
    seg1.update(i, a[i] + i);
    seg2.update(i, a[i] - i);
  }

  while (q--) {
    int op; cin >> op;
    if (op == 1) {
      int k, x; cin >> k >> x;
      seg1.update(k, x + k);
      seg2.update(k, x - k);
    } else {
      int k; cin >> k;
      int ans = min(seg2.query(1, k) + k, seg1.query(k, n) - k);
      cout << ans << '\n';
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int tests = 1;
  while (tests--) run();

  return 0;
}
