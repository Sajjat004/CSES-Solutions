#include <bits/stdc++.h>
using namespace std;

using ll  = long long;
using vll = vector<ll>;
using vi  = vector<int>;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

const int N   = (int) 2e5 + 5;
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9 + 9;

#define nl      '\n'
#define ff      first
#define ss      second
#define szof(x) (int) x.size()
#define all(x)  x.begin(), x.end()

int main() {
  // freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  int test = 1, tc = 0;
  while (test--) {
    ll n; cin >> n;
    int k; cin >> k;
    vll v(k);
    for (ll& x : v) cin >> x;
    vll cntByDivisor(k + 5, 0);
    for (int mask = 1; mask < (1 << k); ++mask) {
      int cnt = 0;
      ll m = n;
      for (int i = 0; i < k; ++i) {
        if (mask & (1 << i)) {
          cnt++;
          m /= v[i];
        }
      }
      cntByDivisor[cnt] += m;
    }
    ll ans = 0;
    for (int i = 1; i <= k; ++i) {
      if (i & 1) ans += cntByDivisor[i];
      else ans -= cntByDivisor[i];
    }
    cout << ans << nl;
  }
  return 0;
}