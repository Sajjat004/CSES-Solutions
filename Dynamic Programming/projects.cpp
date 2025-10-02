#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Project {
  int s, e, p;
  Project(int _s, int _e, int _p) : s(_s), e(_e), p(_p) {}

  bool operator<(const Project& other) const {
    return e == other.e ? s < other.s : e < other.e;
  }
};

void run() {
  int n; cin >> n;
  vector<Project> projects;
  for (int i = 0; i < n; i++) {
    int s, e, p; cin >> s >> e >> p;
    projects.emplace_back(s, e, p);
  }

  sort(projects.begin(), projects.end());

  vector<ll> dp(n + 1);
  dp[0] = projects[0].p;
  for (int i = 1; i < n; ++i) {
    dp[i] = dp[i - 1];
    int idx = -1;
    int lo = 0, hi = i - 1;
    while (lo <= hi) {
      int mid = (lo + hi) >> 1;
      if (projects[mid].e < projects[i].s) {
        idx = mid;
        lo = mid + 1;
      } else {
        hi = mid - 1;
      }
    }
    dp[i] = max(dp[i], (ll) projects[i].p + (idx == -1 ? 0 : dp[idx]));
  }

  cout << dp[n - 1] << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int tests = 1;
  while (tests--) run();

  return 0;
}
