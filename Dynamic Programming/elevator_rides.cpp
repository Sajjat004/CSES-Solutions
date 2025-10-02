#include <bits/stdc++.h>
using namespace std;

void run() {
  int n, W; cin >> n >> W;
  vector<int> w(n);
  for (int i = 0; i < n; i++) cin >> w[i];

  vector<pair<int, int>> dp(1 << n, {INT_MAX, INT_MAX});
  dp[0] = {1, 0};

  for (int mask = 1; mask < (1 << n); ++mask) {
    for (int i = 0; i < n; ++i) {
      if (mask & (1 << i)) {
        auto prev = dp[mask ^ (1 << i)];
        if (prev.second + w[i] <= W) {
          dp[mask] = min(dp[mask], {prev.first, prev.second + w[i]});
        } else {
          dp[mask] = min(dp[mask], {prev.first + 1, w[i]});
        }
      }
    }
  }

  cout << dp[(1 << n) - 1].first << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int tests = 1;
  while (tests--) run();

  return 0;
}
