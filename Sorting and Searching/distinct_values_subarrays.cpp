#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void run() {
  int n; cin >> n;
  vector<int> a(n); for (int& x : a) cin >> x;
  map<int, int> cnt;
  
  ll res = 0;
  for (int left = 0, right = -1; left < n; ++left) {
    while (right + 1 < n && cnt[a[right + 1]] == 0) {
      ++right;
      ++cnt[a[right]];
    }
    res += right - left + 1;
    --cnt[a[left]];
  }

  cout << res << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int tests = 1;
  while (tests--) run();

  return 0;
}
