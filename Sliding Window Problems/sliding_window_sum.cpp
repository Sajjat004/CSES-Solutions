#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int get(int x, int a, int b, int c) {
  return (1LL * x * a + b) % c;
}

void run() {
  int n, k; cin >> n >> k;
  int x, a, b, c; cin >> x >> a >> b >> c;

  int l = x, r = x;
  ll sum = x;
  for (int i = 1; i < k; ++i) {
    r = get(r, a, b, c);
    sum += r;
  }

  ll jor = sum;

  for (int i = k; i < n; ++i) {
    sum -= l;
    l = get(l, a, b, c);
    r = get(r, a, b, c);
    sum += r;
    jor ^= sum;
  }

  cout << jor << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tests = 1;
  while (tests--) run();

  return 0;
}
