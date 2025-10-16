#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

void run() {
  int n, q; cin >> n >> q;
  vector<int> end(N, N + 2);
  for (int i = 0; i < n; ++i) {
    int l, r; cin >> l >> r;
    end[l] = min(end[l], r);
  }

  vector<int> next(N, N + 2);
  for (int i = N - 2; i >= 0; --i) {
    next[i] = min(next[i + 1], end[i]);
  }

  vector<vector<int>> jump(N, vector<int>(20, N + 2));
  for (int i = 0; i < N; ++i) {
    jump[i][0] = next[i];
  }

  for (int k = 1; k < 20; ++k) {
    for (int i = 0; i < N; ++i) {
      jump[i][k] = jump[i][k - 1] < N + 2 ? jump[jump[i][k - 1]][k - 1] : N + 2;
    }
  }

  while (q--) {
    int l, r; cin >> l >> r;
    int res = 0;
    for (int k = 19; k >= 0; --k) {
      if (jump[l][k] <= r) {
        res += 1 << k;
        l = jump[l][k];
      }
    }
    cout << res << '\n';
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tests = 1;
  while (tests--) run();

  return 0;
}
