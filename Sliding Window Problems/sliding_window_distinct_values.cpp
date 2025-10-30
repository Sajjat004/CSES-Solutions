#include <bits/stdc++.h>
using namespace std;

void run() {
  int n, k; cin >> n >> k;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];

  unordered_map<int, int> freq;
  int distinct = 0;
  for (int i = 1; i <= k; i++) {
    if (freq[a[i]]++ == 0) distinct++;
  }

  vector<int> res;
  res.push_back(distinct);

  for (int i = k + 1; i <= n; i++) {
    if (--freq[a[i - k]] == 0) distinct--;
    if (freq[a[i]]++ == 0) distinct++;
    res.push_back(distinct);
  }

  for (int x : res) cout << x << ' ';
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tests = 1;
  while (tests--) run();

  return 0;
}
