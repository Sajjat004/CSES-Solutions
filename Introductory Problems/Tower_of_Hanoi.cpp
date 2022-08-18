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

vector<pii> res;

void solve(int n, int src, int aux, int dest) {
  if (n == 1) {
    res.pb({src, dest});
    return;
  }
  if (n == 2) {
    res.pb({src, aux});
    res.pb({src, dest});
    res.pb({aux, dest});
    return;
  }
  solve(n - 1, src, dest, aux);
  res.pb({src, dest});
  solve(n - 1, aux, src, dest);
}


int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
#endif
  Fast_IO
  int test = 1, tc = 0;
  while (test--) {
    int n; cin >> n;
    solve(n, 1, 2, 3);
    cout << szof(res) << nl;
    for (auto x : res) cout << x.ff << " " << x.ss << nl;
  }
  return 0;
}
