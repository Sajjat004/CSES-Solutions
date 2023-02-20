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
 
class Hashing {
  int add(int a, int b, int mod) { a += b; return a >= mod ? a - mod : a < 0 ? a + mod : a; }
  int mult(int a, int b, int mod) { return (ll) a * b % mod; }
  int power(ll base, ll exp, const int mod) {
    int res = 1;
    base %= mod;
    if (base < 0) base += mod;
    while (exp) {
      if (exp & 1) res = (1LL * res * base) % mod;
      base = (1LL * base * base) % mod;
      exp >>= 1;
    }
    return res;
  }
  int get(char ch) { return ch - 'a' + 1; }
  const int MOD1 = 127657753;
  const int BASE1 = 137;
  const int inveMod1 = power(BASE1, MOD1 - 2, MOD1);
  vector<int> pw, invPw;
  vector<int> hash;
  int n;
  string s;
  void build() {
    hash.push_back(0);
    for (int i = 0; i < n; ++i) {
      int p;
      p = add(hash[i], mult(get(s[i]), pw[i], MOD1), MOD1);
     hash.push_back(p);
    }
  }
public:
  Hashing(string _s) {
    s = _s;
    n = szof(s);
    pw.assign(n + 2, 1);
    invPw.assign(n + 2, 1);
    for (int i = 1; i <= n; ++i) {
      pw[i] = mult(pw[i - 1], BASE1, MOD1);
      invPw[i] = mult(invPw[i - 1], inveMod1, MOD1);
    }
    build();
  }
  int getHash(int l, int r) {
    int p;
    p = mult(add(hash[r], -hash[l - 1], MOD1), invPw[l - 1], MOD1);
    return p;
  }
};
 
int main() {
  // freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(false); cin.tie(0);
  int test = 1, tc = 0;
  while (test--) {
    string s; cin >> s;
    int n = szof(s);
    Hashing hash(s);
    vi ans;
    for (int len = 1; len <= n; ++len) {
      bool possible = 1;
      auto x = hash.getHash(1, len);
      int idx = 1;
      while ((idx + len - 1) <= n) {
        if (x != hash.getHash(idx, idx + len - 1)) {
          possible = 0;
          break;
        }
        idx += len;
      }
      if (idx <= n) {
        int k = n - idx + 1;
        if (hash.getHash(1, k) != hash.getHash(idx, n)) possible = 0;
      }
      if (possible) ans.push_back(len);
    }
    for (int x : ans) cout << x << " ";
    cout << nl;
  }
  return 0;
}