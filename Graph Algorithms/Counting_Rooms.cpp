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

int row, column;
string grid[1005];
vector<vector<bool>> used(1005, vector<bool>(1005, 0));

bool isValid(int x, int y) {
  return (x >= 0 and x < row and y >= 0 and y < column);
}

void dfs(int x, int y) {
  if (!isValid(x, y)) return;
  if (used[x][y]) return;
  used[x][y] = 1;
  dfs(x, y + 1);
  dfs(x + 1, y);
  dfs(x, y - 1);
  dfs(x - 1, y);
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
#endif
  Fast_IO
  int test = 1, tc = 0;
  while (test--) {
    cin >> row >> column;
    int res = 0;
    for (int i = 0; i < row; ++i) cin >> grid[i];
    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < column; ++j) {
        if (grid[i][j] == '#') used[i][j] = 1;
      }
    }
    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < column; ++j) {
        if (!used[i][j]) {
          dfs(i, j);
          res++;
        }
      }
    }
    cout << res << nl;
  }
  return 0;
}
