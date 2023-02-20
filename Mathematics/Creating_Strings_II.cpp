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

int bigMod(int base, int exp, const int mod) {
  int res = 1 % mod;
  base %= mod;
  if (base < 0) base += mod;
  while (exp) {
    if (exp & 1) res = 1LL * res * base % mod;
    base = 1LL * base * base % mod;
    exp >>= 1;
  }
  return res;
}

int modInv(int x, int mod) {
  return bigMod(x, mod - 2, mod);
}

int main() {
  // freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(false); cin.tie(0);
  int test = 1, tc = 0;
  while (test--) {
    string s; cin >> s;
    int n = szof(s);
    int ans = 1;
    vector<int> fact(n + 2, 0);
    fact[0] = fact[1] = 1;
    for (int i = 2; i <= n; ++i) {
      fact[i] = (1LL * fact[i - 1] * i) % MOD;
    }
    ans = fact[n];
    vector<int> cnt(26, 0);
    for (auto x : s) cnt[x - 'a']++;
    for (int i = 0; i < 26; ++i) {
      if (cnt[i] > 1) {
        ans = (1LL * ans * modInv(fact[cnt[i]], MOD)) % MOD;
      }
    }
    cout << ans << nl;
  }
  return 0;
}