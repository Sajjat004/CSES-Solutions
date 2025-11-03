#include <bits/stdc++.h>
using namespace std;

int find(int n, int k) {
  if (n == 1) return 1;
  int removable = (n + 1) / 2;
  if (k <= removable) return (2 * k) > n ? (2 * k) % n : 2 * k;

  int val = find(n / 2, k - removable);
  return (n & 1) ? 2 * val + 1 : 2 * val - 1;
}

void solve() {
  int n, k;
  cin >> n >> k;

  cout << find(n, k) << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tests = 1;
  cin >> tests;
  while (tests--) solve();

  return 0;
}
