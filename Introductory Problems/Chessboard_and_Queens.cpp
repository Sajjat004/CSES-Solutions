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

vi x(20, 0), y(20, 0), z(20, 0);
int res = 0;
string s[10];

void call(int i) {
  if (i == 8) {
    res++;
    return;
  }
  for (int j = 0; j < 8; ++j) {
    if (s[i][j] == '.' and x[j] == 0 and y[i + j] == 0 and z[i - j + 7] == 0) {
      x[j] = 1;
      y[i + j] = 1;
      z[i - j + 7] = 1;
      call(i + 1);
      x[j] = 0;
      y[i + j] = 0;
      z[i - j + 7] = 0;
    }
  }
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
#endif
  Fast_IO
  int test = 1, tc = 0;
  while (test--) {
    for (int i = 0; i < 8; ++i) cin >> s[i];
    call(0);
    cout << res << nl;
  }
  return 0;
}
