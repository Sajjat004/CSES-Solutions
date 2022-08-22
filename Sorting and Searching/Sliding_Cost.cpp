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

multiset<ll> low;
multiset<ll> up;
ll sLow = 0, sUp = 0;
int n, k;

void add(ll val) {
  ll x = (*low.rbegin());
  if (x < val) {
    up.insert(val);
    sUp += val;
    if (szof(up) > (k / 2)) {
      ll move = *up.begin();
      low.insert(move);
      up.erase(up.find(move));
      sUp -= move;
      sLow += move;
    }
  } else {
    low.insert(val);
    sLow += val;
    if (szof(low) > ((k + 1) / 2)) {
      ll move = *low.rbegin();
      low.erase(low.find(move));
      up.insert(move);
      sLow -= move;
      sUp += move;
    }
  }
}

void del(ll val) {
  if (up.find(val) != up.end()) {
    up.erase(up.find(val));
    sUp -= val;
  } else {
    low.erase(low.find(val));
    sLow -= val;
  }

  if (low.empty()) {
    ll move = *up.begin();
    low.insert(move);
    up.erase(up.find(move));
    sUp -= move;
    sLow += move;
  }
}

ll mid() { return (k % 2 == 0) ? 0 : *low.rbegin(); }

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
#endif
  Fast_IO
  int test = 1, tc = 0;
  while (test--) {
    n, k; cin >> n >> k;
    vll v(n, 0);
    for (auto& x : v) cin >> x;
    if (k == 1) {
      for (int i = 1; i <= (n - k + 1); ++i) {
        cout << 0 << " ";
      }
      cout << nl;
      return 0;
    }
    low.insert(v[0]);
    sLow += v[0];
    for (int i = 1; i < k; ++i) add(v[i]);
    cout << sUp - sLow + mid();
    for (int i = k; i < n; ++i) {
      del(v[i - k]);
      add(v[i]);
      cout << " " << sUp - sLow + mid();
    }
    cout << nl;
  }
  return 0;
}
