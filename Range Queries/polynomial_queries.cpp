#include <bits/stdc++.h>
using namespace std;

using ll = long long;

template<typename T>
struct SegTree {
  int n;
  vector<T> tree;
  vector<T> lazy;
  vector<T> cnt;

  SegTree(int n) : n(n), tree(4 * n, 0), lazy(4 * n, 0), cnt(4 * n, 0) {}

  SegTree(int n, vector<int>& a) : n(n), tree(4 * n, 0), lazy(4 * n, 0), cnt(4 * n, 0) {
    build(1, 1, n, a);
  }

  void modify(int l, int r, T val) {
    modify(1, 1, n, l, r, val);
  }

  T query(int l, int r) {
    return query(1, 1, n, l, r);
  }

  void build(int nd, int b, int e, vector<int>& a) {
    if (b == e) {
      tree[nd] = a[b];

      return;
    }

    int mid = (b + e) >> 1;
    build(nd << 1, b, mid, a);
    build(nd << 1 | 1, mid + 1, e, a);
    tree[nd] = tree[nd << 1] + tree[nd << 1 | 1];
  }

  T sum(T a, T d, int len) {
    T sn = (T)len * ((T) 2 * a + (T)(len - 1) * d) / 2;

    return sn;
  }

  void push(int nd, int b, int e) {
    if (lazy[nd] == 0) return;

    tree[nd] += sum(lazy[nd], cnt[nd], e - b + 1);
    if (b != e) {
      lazy[nd << 1] += lazy[nd];
      int mid = (b + e) >> 1;
      lazy[nd << 1 | 1] += lazy[nd] + (cnt[nd] * ((mid - b + 1)));
      cnt[nd << 1] += cnt[nd];
      cnt[nd << 1 | 1] += cnt[nd];
    }
    lazy[nd] = 0;
    cnt[nd] = 0;
  }

  void modify(int nd, int b, int e, int l, int r, T val) {
    push(nd, b, e);

    if (r < b || e < l) return;
    if (l <= b && e <= r) {
      lazy[nd] += val + (b - l);
      cnt[nd]++;
      push(nd, b, e);

      return;
    }

    int mid = (b + e) >> 1;
    modify(nd << 1, b, mid, l, r, val);
    modify(nd << 1 | 1, mid + 1, e, l, r, val);
    tree[nd] = tree[nd << 1] + tree[nd << 1 | 1];
  }

  T query(int nd, int b, int e, int l, int r) {
    push(nd, b, e);

    if (r < b || e < l) return 0;
    if (l <= b && e <= r) return tree[nd];

    int mid = (b + e) >> 1;
    T x = query(nd << 1, b, mid, l, r);
    T y = query(nd << 1 | 1, mid + 1, e, l, r);

    return x + y;
  }
};

void run() {
  int n, q; cin >> n >> q;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];

  SegTree<ll> segTree(n, a);

  while (q--) {
    int t; cin >> t;
    if (t == 1) {
      int l, r; cin >> l >> r;
      segTree.modify(l, r, 1);
    } else {
      int l, r; cin >> l >> r;
      cout << segTree.query(l, r) << '\n';
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tests = 1;
  while (tests--) run();

  return 0;
}
