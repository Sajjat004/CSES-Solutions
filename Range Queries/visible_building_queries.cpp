#include <bits/stdc++.h>
using namespace std;

struct Query {
  int l, r, idx;
  Query(int l, int r, int idx) : l(l), r(r), idx(idx) {}
};

void run() {
  int n, q; cin >> n >> q;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];

  vector<Query> queries[n + 1];
  for (int i = 0; i < q; i++) {
    int l, r; cin >> l >> r;
    queries[l].push_back(Query(l, r, i));
  }

  vector<int> mx;
  vector<int> res(q);

  for (int i = n; i >= 1; --i) {
    while (!mx.empty() && a[mx.back()] <= a[i]) mx.pop_back();
    mx.push_back(i);

    int m = (int)mx.size();

    for (const auto [l, r, idx] : queries[i]) {
      int low = 0, high = m - 1, ans = -1;
      while (low <= high) {
        int mid = (low + high) / 2;
        if (mx[mid] <= r) {
          ans = m - mid;
          high = mid - 1;
        } else {
          low = mid + 1;
        }
      }
      res[idx] = ans;
    }
  }

  for (int i = 0; i < q; i++) cout << res[i] << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tests = 1;
  while (tests--) run();

  return 0;
}
