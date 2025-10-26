#include <bits/stdc++.h>
using namespace std;

int get(string s, int k) {
  int res = 0;
  for (int i = 0; i < k; ++i) {
    if (s[i] == '1') {
      res |= (1 << i);
    }
  }

  return res;
}

void run() {
  int n, k; cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    string s; cin >> s;
    a[i] = get(s, k);
  }

  int res = k;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      res = min(res, __builtin_popcount(a[i] ^ a[j]));
    }
  }

  cout << res << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tests = 1;
  while (tests--) run();

  return 0;
}
