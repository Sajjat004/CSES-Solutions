#include <bits/stdc++.h>
using namespace std;
 
void solve() {
  int n, k; cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  
  map<int, int> freq;
  set<pair<int, int>> s;
  
  auto add = [&](int x) {
    if (freq.count(x)) {
      s.erase({freq[x], -x});
    }
    freq[x]++;
    s.insert({freq[x], -x});
  };
 
  auto remove = [&](int x) {
    s.erase({freq[x], -x});
    freq[x]--;
    if (freq[x] != 0) {
      s.insert({freq[x], -x});
    }
  };
 
  auto getMode = [&]() {
    return -s.rbegin()->second;
  };
 
  for (int i = 0; i < k; ++i) {
    add(a[i]);
  }
  cout << getMode();
  for (int i = k; i < n; ++i) {
    remove(a[i - k]);
    add(a[i]);
    cout << ' ' << getMode();
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
