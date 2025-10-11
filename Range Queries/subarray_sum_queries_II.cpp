#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Node {
  ll pref, suff, total, sum;

  Node(ll _pref, ll _suff, ll _total, ll _sum)
    : pref(_pref), suff(_suff), total(_total), sum(_sum) {}

  Node operator+(const Node& rs) const {
    return Node(
      max(pref, total + rs.pref),
      max(rs.suff, rs.total + suff),
      total + rs.total,
      max({sum, rs.sum, suff + rs.pref})
    );
  }
};

struct SegTree {
  int n;
  vector<Node> tree;

  void build(int nd, int b, int e, vector<ll>& a) {
    if (b == e) {
      tree[nd] = Node(a[b], a[b], a[b], a[b]);
      return;
    }
    int mid = (b + e) >> 1;
    build(nd << 1, b, mid, a);
    build(nd << 1 | 1, mid + 1, e, a);
    tree[nd] = tree[nd << 1] + tree[nd << 1 | 1];
  }

  void update(int nd, int b, int e, int idx, ll val) {
    if (e < idx || idx < b) return;
    if (b == e) {
      tree[nd] = Node(val, val, val, val);
      return;
    }
    int mid = (b + e) >> 1;
    update(nd << 1, b, mid, idx, val);
    update(nd << 1 | 1, mid + 1, e, idx, val);
    tree[nd] = tree[nd << 1] + tree[nd << 1 | 1];
  }

  Node query(int nd, int b, int e, int l, int r) {
    if (r < b || e < l) return Node(INT_MIN, INT_MIN, 0, INT_MIN);
    if (l <= b && e <= r) return tree[nd];
    int mid = (b + e) >> 1;
    Node x = query(nd << 1, b, mid, l, r);
    Node y = query(nd << 1 | 1, mid + 1, e, l, r);
    return x + y;
  }

  SegTree(int _n) : n(_n), tree(4 * n, Node(INT_MIN, INT_MIN, 0, INT_MIN)) {}
  void build(vector<ll>& a) { build(1, 1, n, a); } // array is 1-indexed
  void update(int idx, ll val) { update(1, 1, n, idx, val); }
  ll query(int l, int r) { return query(1, 1, n, l, r).sum; }
};

void run() {
  int n, q; cin >> n >> q;
  vector<ll> a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];

  SegTree seg(n);
  seg.build(a);

  while (q--) {
    int l, r; cin >> l >> r;
    cout << max(0LL, seg.query(l, r)) << '\n';
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int tests = 1;
  while (tests--) run();

  return 0;
}
