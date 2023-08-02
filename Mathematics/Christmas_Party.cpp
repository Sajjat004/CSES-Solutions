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
    int n; cin >> n;
    vi dp(n + 1);
    dp[1] = 0;
    for (int i = 2; i <= n; ++i) {
      dp[i] = (1LL * i * dp[i - 1] + ((i % 2 == 1) ? -1 : 1)) % MOD;
    }
    cout << dp[n] << nl;
  }
  return 0;
}