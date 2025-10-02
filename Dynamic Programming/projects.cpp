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
  projects.emplace_back(INT_MIN, INT_MIN, 0);
  for (int i = 0; i < n; i++) {
    int s, e, p; cin >> s >> e >> p;
    projects.emplace_back(s, e, p);
  }

  sort(projects.begin(), projects.end());

  vector<ll> dp(n + 2);
  dp[0] = 0;
  for (int i = 1; i <= n; ++i) {
    dp[i] = dp[i - 1];
    int idx = upper_bound(projects.begin(), projects.end(), Project(INT_MIN, projects[i].s, INT_MIN)) - projects.begin() - 1;
    dp[i] = max(dp[i], dp[idx] + projects[i].p);
  }

  cout << dp[n] << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int tests = 1;
  while (tests--) run();

  return 0;
}
