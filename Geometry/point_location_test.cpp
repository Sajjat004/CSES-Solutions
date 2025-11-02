#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Point {
  int x, y;

  Point(int x = 0, int y = 0) : x(x), y(y) {}
};

ll colinear(const Point &p1, const Point &p2, const Point &p3) {
  return (ll)(p2.x - p1.x) * (p3.y - p1.y) - (ll)(p2.y - p1.y) * (p3.x - p1.x);
}

void solve() {
  Point p1, p2, p3;
  cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;

  ll coli = colinear(p1, p2, p3);

  string res = "TOUCH";
  if (coli > 0) res = "LEFT";
  else if (coli < 0) res = "RIGHT";

  cout << res << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tests = 1;
  cin >> tests;
  while (tests--) solve();

  return 0;
}
