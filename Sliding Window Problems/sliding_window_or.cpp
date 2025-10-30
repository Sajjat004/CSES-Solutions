#include <bits/stdc++.h>
using namespace std;

struct Data {
  int value, orValue;

  Data(int value = 0, int orValue = 0) : value(value), orValue(orValue) {}
};

struct window {
  stack<Data> s1, s2;

  void push(int x) {
    int newOr = s2.empty() ? x : (s2.top().orValue | x);
    s2.push(Data(x, newOr));
  }

  void pop() {
    if (s1.empty()) {
      while (!s2.empty()) {
        int newOr = s1.empty() ? s2.top().value : (s1.top().orValue | s2.top().value);
        s1.push(Data(s2.top().value, newOr));
        s2.pop();
      }
    }
    s1.pop();
  }

  int getOr() {
    int res = 0;
    if (s1.empty()) res = s2.top().orValue;
    else if (s2.empty()) res = s1.top().orValue;
    else res = s1.top().orValue | s2.top().orValue;

    return res;
  }
};

int getElement(int x, int a, int b, int c) {
  return (1LL * x * a + b) % c;
}

void run() {
  int n, k; cin >> n >> k;
  int x, a, b, c; cin >> x >> a >> b >> c;
  window win;
  win.push(x);
  for (int i = 2; i <= k; ++i) {
    x = getElement(x, a, b, c);
    win.push(x);
  }

  int xorRes = win.getOr();

  for (int i = k + 1; i <= n; ++i) {
    win.pop();
    x = getElement(x, a, b, c);
    win.push(x);
    xorRes ^= win.getOr();
  }

  cout << xorRes << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tests = 1;
  while (tests--) run();

  return 0;
}
