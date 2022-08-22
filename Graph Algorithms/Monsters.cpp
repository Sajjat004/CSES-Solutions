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

int dx[8] = { 0, -1, 0, 1, -1, -1, 1, 1 };
int dy[8] = { -1, 0, 1, 0, -1, 1, 1, -1 };

int n, m;

string grid[1005];

bool isValid(int x, int y) {
  return (x >= 0 and x < n and y >= 0 and y < m and grid[x][y] != '#');
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
#endif
  Fast_IO
  int test = 1, tc = 0;
  while (test--) {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> grid[i];
    vector<vi> dist1(n + 2, vi(m + 2, INF));
    vector<vi> dist2(n + 2, vi(m + 2, INF));
    queue<pii> q;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (grid[i][j] == 'A') {
          dist1[i][j] = 0;
          q.push({i, j}); 
        }
      }
    }
    vector<vector<pii>> path(n + 2, vector<pii>(m + 2, {-1, -1}));
    vector<vi> dir(n + 2, vi(m + 2, -1));
    while (!q.empty()) {
      int x = q.front().ff;
      int y = q.front().ss;
      q.pop();
      for (int i = 0; i < 4; ++i) {
        if (isValid(x + dx[i], y + dy[i]) and dist1[x + dx[i]][y + dy[i]] == INF) {
          dist1[x + dx[i]][y + dy[i]] = dist1[x][y] + 1;
          path[x + dx[i]][y + dy[i]] = {x, y};
          dir[x + dx[i]][y + dy[i]] = i;
          q.push({x + dx[i], y + dy[i]});
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (grid[i][j] == 'M') {
          dist2[i][j] = 0;
          q.push({i, j}); 
        }
      }
    }

    while (!q.empty()) {
      int x = q.front().ff;
      int y = q.front().ss;
      q.pop();
      for (int i = 0; i < 4; ++i) {
        if (isValid(x + dx[i], y + dy[i]) and dist2[x + dx[i]][y + dy[i]] == INF) {
          dist2[x + dx[i]][y + dy[i]] = dist2[x][y] + 1;
          q.push({x + dx[i], y + dy[i]});
        }
      }
    }
    string d = "LURD";
    bool done = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (i == 0 or j == 0 or i == (n - 1) or j == (m - 1)) {
          if (dist1[i][j] != INF and dist1[i][j] < dist2[i][j]) {
            int x = i, y = j;
            vector<char> res;
            while (grid[x][y] == '.') {
              res.pb(d[dir[x][y]]);
              int temp1 = path[x][y].ff;
              int temp2 = path[x][y].ss;
              x = temp1;
              y = temp2;
            }
            cout << "YES" << nl << szof(res) << nl;
            reverse(all(res));
            for (auto x : res) cout << x;
            cout << nl;
            return 0;
          }
        }
      }
    }

    cout << "NO" << nl;
  }
  return 0;
}
