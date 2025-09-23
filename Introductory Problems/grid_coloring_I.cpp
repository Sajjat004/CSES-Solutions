#include <bits/stdc++.h>
using namespace std;

void run() {
  int H, W; cin >> H >> W;
  vector<string> grid(H);
  for (int i = 0; i < H; ++i) {
    cin >> grid[i];
  }

  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      set<char> s;
      if (i > 0) s.insert(grid[i - 1][j]);
      if (j > 0) s.insert(grid[i][j - 1]);
      s.insert(grid[i][j]);
      for (char c = 'A'; c <= 'D'; ++c) {
        if (!s.count(c)) {
          grid[i][j] = c;
          break;
        }
      }
    }
  }

  for (auto x : grid) cout << x << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int tests = 1;
  while (tests--) run();

  return 0;
}
