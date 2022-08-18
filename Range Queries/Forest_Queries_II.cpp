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

struct FenwickTree {
  vector<int> tree;
  int n;

  FenwickTree(int n) {
    this->n = n;
    tree.assign(n + 2, 0);
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
};

vector<vector<bool>> grid(1001, vector<bool>(1001, 0));
vector<vector<int>> dp(1001, vector<int>(1001, 0));

void buildDp(int n) {
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      dp[i][j] = grid[i][j] + dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1];
    }
  }
}

vector<FenwickTree> rowUpdate(1001, FenwickTree(1001));

void update(int x, int y, int n) {
  int val = -1;
  if (grid[x][y] == 0) val = 1;
  grid[x][y] = !grid[x][y];
  for (int i = x; i <= n; ++i) rowUpdate[i].update(y, val);
}

int get(int x, int y) {
  return dp[x][y] + rowUpdate[x].query(y);
}

int query(int x1, int y1, int x2, int y2) {
  return get(x2, y2) - get(x2, y1 - 1) - get(x1 - 1, y2) + get(x1 - 1, y1 - 1);
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
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        char ch; cin >> ch;
        if (ch == '*') grid[i][j] = 1;
      }
    }

    buildDp(n);

    while (q--) {
      int op; cin >> op;
      if (op == 1) {
        int x, y; cin >> x >> y;
        update(x, y, n);
      } else {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        cout << query(x1, y1, x2, y2) << nl;
      }
    }
  }
  return 0;
}
