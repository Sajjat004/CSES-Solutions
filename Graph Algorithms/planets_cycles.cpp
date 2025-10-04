#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
vector<int> tele(N), len(N);
vector<bool> vis(N, false);
int score = 0;
queue<int> path;

void dfs(int u) {
  path.push(u);
  if (vis[u]) {
    score += len[u];
    return;
  }
  vis[u] = true;
  score++;
  dfs(tele[u]);
}

void run() {
  int n; cin >> n;
  for (int i = 1; i <= n; ++i) cin >> tele[i];

  for (int u = 1; u <= n; ++u) {
    if (vis[u]) continue;
    score = 0;
    while (!path.empty()) path.pop();
    dfs(u);
    int dec = 1;
    while (!path.empty()) {
      if (path.front() == path.back()) dec = 0;
      len[path.front()] = score;
      score -= dec;
      path.pop();
    }
  }

  for (int u = 1; u <= n; ++u)
    cout << len[u] << ' ';
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int tests = 1;
  while (tests--) run();

  return 0;
}
