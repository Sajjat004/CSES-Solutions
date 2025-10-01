#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int n;
ll a[5001], memo[5001][5001][2];
bool vis[5001][5001][2];
 
ll dp(int i, int j, bool turn) {
  if (i > j) return 0;
  if (vis[i][j][turn]) return memo[i][j][turn];
  vis[i][j][turn] = true;
  if (turn) {
    return memo[i][j][turn] = max(a[i] + dp(i + 1, j, !turn), a[j] + dp(i, j - 1, !turn));
  } else {
    return memo[i][j][turn] = min(dp(i + 1, j, !turn), dp(i, j - 1, !turn));
  }
}
 
 
void run() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  memset(memo, -1, sizeof(memo));
  memset(vis, 0, sizeof(vis));
 
  cout << dp(1, n, 1) << "\n";
}
 
int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
 
  int tests = 1;
  while (tests--) run();
 
  return 0;
}
