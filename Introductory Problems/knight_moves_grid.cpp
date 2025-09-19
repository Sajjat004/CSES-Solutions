#include <bits/stdc++.h>
using namespace std;
 
int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
 
struct Point {
  int x, y, d;
  Point(int _x, int _y, int _d) : x(_x), y(_y), d(_d) {}
};
 
void run() {
  int n; cin >> n;
  vector<vector<int>> grid(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> grid[i][j];
    }
  }
 
  queue<Point> q;
  vector<vector<bool>> vis(n, vector<bool>(n, false));
  vector<vector<int>> dist(n, vector<int>(n, 0));
  q.push(Point(0, 0, 0));
  vis[0][0] = true;
 
  auto isValid = [&](int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n && !vis[x][y];
  };
 
  while (!q.empty()) {
    auto [x, y, d] = q.front(); q.pop();
    for (int i = 0; i < 8; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (isValid(nx, ny)) {
        vis[nx][ny] = true;
        dist[nx][ny] = d + 1;
        q.push(Point(nx, ny, d + 1));
      }
    }
  }
 
 
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << dist[i][j] << ' ';
    }
    cout << '\n';
  }
}
 
int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
 
  int tests = 1;
  while (tests--) run();
 
  return 0;
}
