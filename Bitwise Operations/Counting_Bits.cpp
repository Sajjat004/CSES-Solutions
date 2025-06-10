#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solution() {
  ll n; cin >> n;
  ll countOne = 0;
  for (int bitPos = 0; (1LL << bitPos) <= n; ++bitPos) {
    ll pairs = (n + 1) / (1LL << bitPos);
    ll remainder = (n + 1) % (1LL << bitPos);
    countOne += ((pairs) / 2) * (1LL << bitPos);
    if (pairs % 2 == 1) countOne += min(remainder, 1LL << bitPos);
  }

  cout << countOne << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  solution();

  return 0;
}
