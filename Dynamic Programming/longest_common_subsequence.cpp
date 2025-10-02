#include <bits/stdc++.h>
using namespace std;

void run() {
  int n, m; cin >> n >> m;
  vector<int> a(n); for (int &x : a) cin >> x;
  vector<int> b(m); for (int &x : b) cin >> x;

  int dp[n + 1][m + 1];
  memset(dp, 0, sizeof(dp));

  for (int i = n - 1; i >= 0; --i) {
    for (int j = m - 1; j >= 0; --j) {
      if (a[i] == b[j]) dp[i][j] = 1 + dp[i + 1][j + 1];
      else dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
    }
  }

  cout << dp[0][0] << '\n';
  int x = 0, y = 0;
  while (x < n && y < m) {
    if (a[x] == b[y]) {
      cout << a[x] << ' ';
      ++x; ++y;
    } else if (dp[x + 1][y] >= dp[x][y + 1]) {
      ++x;
    } else {
      ++y;
    }
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int tests = 1;
  while (tests--) run();

  return 0;
}
