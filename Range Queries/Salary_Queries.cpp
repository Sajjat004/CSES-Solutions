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
const int mxN     = (int) 2e6 + 6;
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

class Bit {
  vi tree;
  int n;
public:
  Bit(int n) {
    this->n = n;
    tree.resize(mxN, 0);
  }

  void update(int idx, int val) {
    while (idx <= n) {
      tree[idx] += val;
      idx += (idx & -idx);
    }
  }

  int query(int idx) {
    int sum = 0;
    while (idx > 0) {
      sum += tree[idx];
      idx -= (idx & -idx);
    }
    return sum;
  }

  int query(int l, int r) {
    return query(r) - query(l - 1);
  }
};

unordered_map<int, int> m;
int cnt = 0;

int get(int n) {
  return m[n];
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
#endif
  Fast_IO
  int test = 1, tc = 0;
  while (test--) {
    int n, q; cin >> n >> q;
    int salary[n + 2];
    vi cmpress;
    for (int i = 1; i <= n; ++i) {
      cin >> salary[i];
      cmpress.pb(salary[i]);
    }

    vector<pair<int, pii>> query;
    for (int i = 1; i <= q; ++i) {
      char a;
      int b, c; cin >> a >> b >> c;
      query.pb({a, {b, c}});
      if (a == '!') cmpress.pb(c);
      else {
        cmpress.pb(b);
        cmpress.pb(c);
      }
    }
    sort(all(cmpress));
    cmpress.erase(unique(all(cmpress)), cmpress.end());
    cnt = szof(cmpress) + 2;
    Bit ds(cnt);

    for (int i = 1; i <= n; ++i) {
      int idx = upper_bound(all(cmpress), salary[i]) - cmpress.begin();
      ds.update(idx, 1);
    }

    for (auto p : query) {
      if (p.ff == '!') {
        int k, x;
        k = p.ss.ff;
        x = p.ss.ss;
        int idx = upper_bound(all(cmpress), salary[k]) - cmpress.begin();
        ds.update(idx, -1);
        salary[k] = x;
        idx = upper_bound(all(cmpress), salary[k]) - cmpress.begin();
        ds.update(idx, 1);
      } else {
        int a, b;
        a = p.ss.ff;
        b = p.ss.ss;
        int l = upper_bound(all(cmpress), a) - cmpress.begin();
        int r = upper_bound(all(cmpress), b) - cmpress.begin();
        cout << ds.query(l, r) << nl;
      }
    }
  }
  return 0;
}
