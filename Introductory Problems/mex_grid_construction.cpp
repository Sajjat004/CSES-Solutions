#include <bits/stdc++.h>
using namespace std;

void run() {
  int n; cin >> n;
  vector<int> have((n * n) + 1, 0);

  function<int()> mex = [&]() -> int {
    for (int i = 0; i <= n * n; ++i) {
      if (have[i] == 0) return i;
    }
    return n * n + 1;
  };

  vector<vector<int>> res(n, vector<int>(n, -1));

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < i; ++k) have[res[k][j]]++;
      res[i][j] = mex();
      for (int k = 0; k < i; ++k) have[res[k][j]]--;
      have[res[i][j]]++;
    }
    for (int j = 0; j < n; ++j) have[res[i][j]]--;
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << res[i][j] << ' ';
    }
    cout << '\n';
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int tests = 1;
  while (tests--) run();

  return 0;
}
