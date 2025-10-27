//  author: md. sajjat hossen
// created: 2025-10-27 11:15:39

#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 1;

void run() {
  int n, m; cin >> n >> m;

  vector<vector<int>> revAdj(n + 1);
  vector<int> revIndeg(n + 1, 0);
  for (int i = 0; i < m; ++i) {
    int u, v; cin >> u >> v;
    revAdj[v].push_back(u);
    revIndeg[u]++;
  }

  vector<bitset<N>> mask(n + 1);

  queue<int> q;
  for (int i = 1; i <= n; ++i) {
    if (revIndeg[i] == 0) {
      q.push(i);
      mask[i].set(i);
    }
  }

  while (!q.empty()) {
    int u = q.front(); q.pop();

    for (int v : revAdj[u]) {
      mask[v] |= mask[u];
      revIndeg[v]--;
      if (revIndeg[v] == 0) {
        q.push(v);
        mask[v].set(v);
      }
    }
  }

  for (int i = 1; i <= n; ++i) {
    cout << mask[i].count() << ' ';
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tests = 1;
  while (tests--) run();

  return 0;
}
