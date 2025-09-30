#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int memo[1000005][2];

int dp(int pos, bool midLine) {
  if (pos == 1) return 1;
  if (memo[pos][midLine] != -1) return memo[pos][midLine];

  int res = dp(pos - 1, false); if (res >= mod) res -= mod;
  res += dp(pos - 1, true); if (res >= mod) res -= mod;
  res += dp(pos - 1, midLine); if (res >= mod) res -= mod;

  if (midLine) {
    res += dp(pos - 1, true); if (res >= mod) res -= mod;
    res += dp(pos - 1, true); if (res >= mod) res -= mod;
  }

  return memo[pos][midLine] = res;
}

void run() {
  int n; cin >> n;
  cout << (dp(n, false) + dp(n, true)) % mod << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  memset(memo, -1, sizeof(memo));
  int tests = 1; cin >> tests;
  while (tests--) run();

  return 0;
}
