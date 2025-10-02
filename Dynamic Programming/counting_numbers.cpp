#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> digits;
ll memo[20][10][2];

ll dp(int pos, int last, bool smaller) {
  if (pos == (int)digits.size()) return 1;
  if (memo[pos][last][smaller] != -1) return memo[pos][last][smaller];
  ll ans = 0;
  for (int d = 0; d <= 9; d++) {
    if (d == last) continue;
    if (!smaller && d > digits[pos]) continue;
    ans += dp(pos + 1, d, smaller || (d < digits[pos]));
  }
  return memo[pos][last][smaller] = ans;
}

ll getResult(ll x) {
  if (x < 0) return 0;
  if (x == 0) return 1;

  digits.clear();
  for (ll temp = x; temp > 0; temp /= 10) {
    digits.push_back(temp % 10);
  }
  reverse(digits.begin(), digits.end());
  memset(memo, -1, sizeof(memo));
  ll res = 1;
  for (int d = 1; d <= digits[0]; d++) {
    if (d < digits[0]) {
      res += dp(1, d, true);
    } else {
      res += dp(1, d, false);
    }
  }
  for (int i = 1; i < (int)digits.size(); i++) {
    for (int first = 1; first <= 9; first++) {
      res += dp(i + 1, first, true);
    }
  }
  
  return res;
}

void run() {
  ll a, b; cin >> a >> b;
  
  ll ansB = getResult(b);
  ll ansA = getResult(a - 1);

  cout << ansB - ansA << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int tests = 1;
  while (tests--) run();

  return 0;
}
