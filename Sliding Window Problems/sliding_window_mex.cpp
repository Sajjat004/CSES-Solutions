#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];

  map<int, int> freq;
  set<int> missings;

  auto add = [&] (int x) {
    if (x > n) return;
    if (freq[x] == 0) {
      missings.erase(x);
    }
    freq[x]++;
  };

  auto remove = [&] (int x) {
    if (x > n) return;
    freq[x]--;
    if (freq[x] == 0) {
      missings.insert(x);
    }
  };

  auto getMex = [&] () {
    if (missings.empty()) return n;
    return *missings.begin();
  };

  for (int i = 0; i <= n; ++i) missings.insert(i);

  for (int i = 0; i < k; ++i) add(a[i]);
  cout << getMex();
  for (int i = k; i < n; ++i) {
    remove(a[i - k]);
    add(a[i]);
    cout << ' ' << getMex();
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tests = 1;
  while (tests--) solve();

  return 0;
}
