#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
int memo[(1 << 21) + 1][21];

int dfs(int u, int mask, vector<vector<int>>& adj, int n) {
  if (u == n) {
    for (int i = 1; i < n; i++) {
      if (!(mask & (1 << (i - 1)))) return 0;
    }
    return 1;
  }

  if (memo[mask][u] != -1) return memo[mask][u];
  int res = 0;
  for (auto v : adj[u]) {
    if (!(mask & (1 << (v - 1)))) {
      res = (res + dfs(v, mask | (1 << (v - 1)), adj, n)) % MOD;
    }
  }
  return memo[mask][u] = res;
}

void run() {
  memset(memo, -1, sizeof(memo));

  int n, m; cin >> n >> m;
  vector<vector<int>> adj(n + 5);
  for (int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
  }

  cout << dfs(1, 1, adj, n) << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int tests = 1;
  while (tests--) run();

  return 0;
}
