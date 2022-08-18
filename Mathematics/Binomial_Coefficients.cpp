#include <bits/stdc++.h>
using namespace std;

typedef long long           ll;
typedef long double         ld;
typedef unsigned long long  ull;
typedef pair <int, int>     pii;
typedef pair <ll, ll>       pll;
typedef vector <int>        vi;
typedef vector <ll>         vll;

const int N       = (int) 2e5 + 5;
const int mxN     = (int) 1e6 + 6;
const int MOD     = (int) 1e9 + 7;
const int INF     = (int) 1e9 + 9;
const double EPS  = (double) 1e-9;

#define debug(x)  cerr << #x << " = " << x << '\n';
#define all(x)    x.begin(), x.end()
#define szof(x)   (int) x.size()
#define ff        first
#define ss        second
#define pb        push_back
#define mp        make_pair
#define PI        acos(-1.0)
#define nl        '\n'
#define Fast_IO   ios_base::sync_with_stdio(false); cin.tie(0);

/*........................ let's try one more time ........................*/

int bigMod(int base, int exp, const int mod) {
  int res = 1 % mod;
  base %= mod;
  if (base < 0) base += mod;
  while (exp) {
    if (exp & 1) res = (1LL * res * base) % mod;
    base = (1LL * base * base) % mod;
    exp >>= 1;
  }
  return res;
}

vi fact(mxN + 2, 0);

void preCal() {
  fact[0] = fact[1] = 1;
  for (int i = 2; i <= mxN; ++i) {
    fact[i] = (1LL * fact[i - 1] * i) % MOD;
  }
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
#endif
  Fast_IO
  int test = 1, tc = 0;
  preCal();
  cin >> test;
  while (test--) {
    int a, b; cin >> a >> b;
    int x = (1LL * fact[a] * bigMod(fact[b], MOD - 2, MOD)) % MOD;
    int y = fact[a - b];
    y = bigMod(y, MOD - 2, MOD);
    cout << (1LL * x * y) % MOD << nl;
  }
  return 0;
}
