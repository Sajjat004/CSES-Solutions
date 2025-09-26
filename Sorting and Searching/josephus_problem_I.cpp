#include <bits/stdc++.h>
using namespace std;

void run() {
  int n; cin >> n;
  int k = 1;
  int sqrtVal = sqrt(n);
  vector<vector<int>> a;
  vector<int> temp;
  for (int i = 1; i <= n; ++i) {
    temp.push_back(i);
    if (i % sqrtVal == 0 || i == n) {
      a.push_back(temp);
      temp.clear();
    }
  }

  vector<int> order;
  int col = 0, row = 0;
  for (int i = 0; i < n; ++i) {
    int jump = k % (n - i);
    while (jump) {
      if (col + jump < (int) a[row].size()) {
        col += jump;
        jump = 0;
      } else {
        jump -= (int) a[row].size() - col;
        col = 0;
        do {
          row = (row + 1) % (int) a.size();
        } while (a[row].empty());
      }
    }
    order.push_back(a[row][col]);
    a[row].erase(a[row].begin() + col);
    if (i == n - 1) break;
    if (col == (int) a[row].size()) {
      col = 0;
      do {
        row = (row + 1) % (int) a.size();
      } while (a[row].empty());
    }
  }

  for (int x : order) {
    cout << x << ' ';
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int tests = 1;
  while (tests--) run();

  return 0;
}
