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

#ifdef LOCAL
#include "headerFile/debug.h"
#endif

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

int phi(int n) {
  int m = n;
  set<int> s;
  for (int i = 2; i * i <= m; ++i) {
    while (m % i == 0) {
      s.insert(i);
      m /= i;
    }
  }
  if (m > 1) s.insert(m);
  for (auto x : s) {
    n = (n - (n / x));
  }
  return n;
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
#endif
  Fast_IO
  int test = 1, tc = 0;
  cin >> test;
  int p = phi(MOD);
  int q = phi(p);
  while (test--) {
    int a, b, c; cin >> a >> b >> c;
    int x = bigMod(a, (bigMod(b, c % q, p)), MOD);
    cout << x << nl;
  }
  return 0;
}
