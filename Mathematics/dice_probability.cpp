#include <bits/stdc++.h>
using namespace std;

using ld = long double;

void solve() {
  int n, a, b;
  cin >> n >> a >> b;

  vector<vector<ld>> dp(n + 1, vector<ld>(b + 1, 0.0));
  dp[0][0] = 1.0;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= b; ++j) {
      for (int k = 1; k <= 6; ++k) {
        if (j - k >= 0) {
          dp[i][j] += dp[i - 1][j - k];
        }
      }
      dp[i][j] /= 6.0;
    }
  }

  ld ans = 0.0;
  for (int i = a; i <= b; i++) {
    ans += dp[n][i];
  }

  cout << fixed << setprecision(6) << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tests = 1;
  while (tests--) solve();

  return 0;
}
