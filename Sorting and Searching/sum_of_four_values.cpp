#include <bits/stdc++.h>
using namespace std;

void run() {
  int n, target; cin >> n >> target;
  vector<int> a(n); for (int &x : a) cin >> x;
  unordered_map<int, vector<pair<int, int>>> mp;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      mp[a[i] + a[j]].push_back({i, j});
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int need = target - (a[i] + a[j]);
      if (mp.count(need)) {
        for (auto &[x, y] : mp[need]) {
          if (x != i && x != j && y != i && y != j) {
            cout << i + 1 << ' ' << j + 1 << ' ' << x + 1 << ' ' << y + 1 << '\n';
            return;
          }
        }
      }
    }
  }

  cout << "IMPOSSIBLE\n";
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int tests = 1;
  while (tests--) run();

  return 0;
}
