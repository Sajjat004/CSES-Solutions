#include <bits/stdc++.h>
using namespace std;
 
template<typename T>
struct FenwickTree2D {
  int n, m;
  vector<vector<T>> fenw;
 
  FenwickTree2D(int _n, int _m) : n(_n), m(_m), fenw(n + 1, vector<T>(m + 1, 0)) {}
 
  void modify(int r, int c, T delta) { // add delta to (r,c)
    for (int i = r; i <= n; i += i & -i) {
      for (int j = c; j <= m; j += j & -j) {
        fenw[i][j] += delta;
      }
    }
  }
 
  T query(int r, int c) { // sum from (1,1) to (r,c)
    T sum = 0;
    for (int i = r; i > 0; i -= i & -i) {
      for (int j = c; j > 0; j -= j & -j) {
        sum += fenw[i][j];
      }
    }
    return sum;
  }
 
  T query(int r1, int c1, int r2, int c2) { // sum from (r1,c1) to (r2,c2)
    return query(r2, c2) - query(r1 - 1, c2) - query(r2, c1 - 1) + query(r1 - 1, c1 - 1);
  }
};
 
void run() {
  int n, q; cin >> n >> q;
  FenwickTree2D<int> fenw(n, n);
  for (int r = 1; r <= n; r++) {
    for (int c = 1; c <= n; c++) {
      char x; cin >> x;
      if (x == '*') fenw.modify(r, c, 1);
    }
  }
 
  while (q--) {
    int op; cin >> op;
    if (op == 1) {
      int r, c; cin >> r >> c;
      int cur = fenw.query(r, c, r, c);
      fenw.modify(r, c, cur == 0 ? 1 : -1);
    } else {
      int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
      cout << fenw.query(r1, c1, r2, c2) << '\n';
    }
  }
}
 
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
 
  int tests = 1;
  while (tests--) run();
 
  return 0;
}
