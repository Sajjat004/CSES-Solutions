#include <bits/stdc++.h>
using namespace std;

void run() {
  int n, m; cin >> n >> m;
  vector<vector<int>> radj(n + 1, vector<int>());
  vector<int> outDeg(n + 1, 0);
  
  for (int i = 0; i < m; ++i) {
    int u, v; cin >> u >> v;
    radj[v].push_back(u);
    outDeg[u]++;
  }

  priority_queue<int> q;
  for (int i = 1; i <= n; ++i) {
    if (outDeg[i] == 0) q.push(i);
  }

  vector<int> order;
  while (!q.empty()) {
    int u = q.top(); q.pop();
    order.push_back(u);
    for (int v : radj[u]) {
      outDeg[v]--;
      if (outDeg[v] == 0) q.push(v);
    }
  }

  reverse(order.begin(), order.end());
  for (int u : order) cout << u << ' ';
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int tests = 1;
  while (tests--) run();

  return 0;
}
