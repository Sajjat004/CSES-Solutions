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

int n, m;
string grid[1005];
vector<vector<bool>> used(1005, vector<bool>(1005, 0));
vector<vector<int>> prestep(1005, vector<int>(1005, -1));
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
string setDir = "URDL";

bool isValid(int x, int y) {
  return (x >= 0 and x < n and y >= 0 and y < m);
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
    pii begin, end;
    for (int i = 0; i < n; ++i) cin >> grid[i];
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (grid[i][j] == 'A') begin = {i, j};
        else if (grid[i][j] == 'B') end = {i, j};
      }
    }
    queue<pii> q;
    q.push(begin);
    used[begin.ff][begin.ss] = 1;
    while (!q.empty()) {
      pii u = q.front();
      q.pop();
      for (int i = 0; i < 4; ++i) {
        pii v = {u.ff + dx[i], u.ss + dy[i]};
        if (!isValid(v.ff, v.ss)) continue;
        if (grid[v.ff][v.ss] == '#') continue;
        if (used[v.ff][v.ss]) continue;
        prestep[v.ff][v.ss] = i;
        used[v.ff][v.ss] = 1;
        q.push(v);
      }
    }
    if (used[end.ff][end.ss]) {
      vector<int> steps;
      while (end != begin) {
        int p = prestep[end.ff][end.ss];
        steps.push_back(p);
        end = {end.ff - dx[p], end.ss - dy[p]};
      }
      reverse(all(steps));
      cout << "YES" << nl;
      cout << steps.size() << nl;
      for (auto x : steps) cout << setDir[x];
      cout << nl;
    } else cout << "NO" << nl;
  }
  return 0;
}
