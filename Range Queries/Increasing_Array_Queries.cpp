#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<typename T>
struct SegTree {
  int n;
  vector<T> tree;
  vector<T> lazy;
  
  SegTree(int n) : n(n), tree(4 * n, 0), lazy(4 * n, 0) {}

  SegTree(int n, vector<T>& a) : n(n), tree(4 * n, 0), lazy(4 * n, 0) {
    build(1, 1, n, a);
  }

  void modify(int l, int r, T val) {
    modify(1, 1, n, l, r, val);
  }

  T query(int l, int r) {
    return query(1, 1, n, l, r);
  }

  void build(int nd, int b, int e, vector<T>& a) {
    if (b == e) {
      tree[nd] = a[b];

      return;
    }

    int mid = (b + e) >> 1;
    build(nd << 1, b, mid, a);
    build(nd << 1 | 1, mid + 1, e, a);
    tree[nd] = tree[nd << 1] + tree[nd << 1 | 1];
  }

  void push(int nd, int b, int e) {
    if (lazy[nd] == 0) return;

    tree[nd] = lazy[nd] * (e - b + 1);
    if (b != e) {
      lazy[nd << 1] = lazy[nd];
      lazy[nd << 1 | 1] = lazy[nd];
    }
    lazy[nd] = 0;
  }

  void modify(int nd, int b, int e, int l, int r, T val) {
    push(nd, b, e);

    if (r < b || e < l) return;
    if (l <= b && e <= r) {
      lazy[nd] = val;
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

template<typename T>
struct PrefixSum {
  int n;
  vector<T> sum;

  PrefixSum(int n) : n(n), sum(n + 1, 0) {}

  PrefixSum(int n, const vector<T>& a) : n(n), sum(n + 1, 0) {
    build(a);
  }

  void build(const vector<T>& a) {
    for (int i = 1; i <= n; ++i) {
      sum[i] = sum[i - 1] + a[i];
    }
  }

  T query(int l, int r) {
    return sum[r] - sum[l - 1];
  }
};

struct Query {
  int idx, l, r;
  Query(int idx, int l, int r) : idx(idx), l(l), r(r) {}
};

void run() {
  int n, q; cin >> n >> q;
  vector<ll> a(n + 1);
  for (int i = 1; i <= n; ++i) cin >> a[i];

  PrefixSum<ll> ps(n, a);
  SegTree<ll> seg(n);

  vector<Query> queries[n + 1];
  for (int i = 1; i <= q; ++i) {
    int l, r; cin >> l >> r;
    queries[l].emplace_back(i, l, r);
  }

  stack<int> maxes;
  vector<ll> res(q + 1, 0);

  for (int i = n; i >= 1; --i) {
    while (!maxes.empty() && a[maxes.top()] <= a[i]) maxes.pop();
    int nxt = maxes.empty() ? n : maxes.top() - 1;
    seg.modify(i, nxt, a[i]);
    maxes.push(i);

    for (auto [idx, l, r] : queries[i]) {
      ll total = ps.query(l, r);
      ll segsum = seg.query(l, r);
      res[idx] = segsum - total;
    }
  }

  for (int i = 1; i <= q; ++i) {
    cout << res[i] << '\n';
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tests = 1;
  while (tests--) run();

  return 0;
}
