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

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
#endif
  Fast_IO
  int test = 1, tc = 0;
  while (test--) {
    int n, m; cin >> n >> m;
    vi v(n + 2, 0), pos(n + 2, 0);
    for (int i = 1; i <= n; ++i) {
      cin >> v[i];
      pos[v[i]] = i;
    }
    int res = 1;
    for (int i = 2; i <= n; ++i) {
      if (pos[i] < pos[i - 1]) res++;
    }
    while (m--) {
      int l, r; cin >> l >> r;
      set<pii> s;
      if (v[l] + 1 <= n) s.insert({v[l], v[l] + 1});
      if (v[l] - 1 > 0) s.insert({v[l] - 1, v[l]});
      if (v[r] + 1 <= n) s.insert({v[r], v[r] + 1});
      if (v[r] - 1 > 0) s.insert({v[r] - 1, v[r]});
      for (auto x : s) {
        if (pos[x.ss] < pos[x.ff]) res--;
      }

      swap(v[l], v[r]);
      pos[v[l]] = l;
      pos[v[r]] = r;
      for (auto x : s) {
        if (pos[x.ss] < pos[x.ff]) res++;
      }
      cout << res << nl;
    }
  }
  return 0;
}
