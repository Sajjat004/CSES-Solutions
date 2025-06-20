#include <bits/stdc++.h>
using namespace std;

class MathUtils {
public:
  vector<int> factorial;
  vector<int> inverseFactorial;
  int n;
  int mod;

  int power(int base, int exp) {
    int res = 1 % mod;
    base %= mod;
    if (base < 0) base += mod;
    while (exp) {
      if (exp & 1) res = 1LL * res * base % mod;
      base = 1LL * base * base % mod;
      exp >>= 1;
    }
    return res;
  }

  int add(int a, int b) { return (a + b) % mod; }
  int subtract(int a, int b) { return (a - b + mod) % mod; }
  int multiply(int a, int b) { return 1LL * a * b % mod; }

  void buildFactorial(int n) {
    factorial.resize(n + 1);
    inverseFactorial.resize(n + 1);
    factorial[0] = 1;
    for (int i = 1; i <= n; ++i) {
      factorial[i] = 1LL * factorial[i - 1] * i % mod;
    }
    inverseFactorial[n] = power(factorial[n], mod - 2);
    for (int i = n - 1; i >= 0; --i) {
      inverseFactorial[i] = 1LL * inverseFactorial[i + 1] * (i + 1) % mod;
    }
  }

  MathUtils(int n, const int mod) : n(n), mod(mod) {
    buildFactorial(n);
  }

  int ncr(int n, int k) {
    if (k < 0 || k > n) return 0;
    return 1LL * factorial[n] * inverseFactorial[k] % mod * inverseFactorial[n - k] % mod;
  }
};

void solution() {
  const int MOD = 1e9 + 7;
  int n; cin >> n;
  string s; cin >> s;

  int opening = 0, closing = 0, cnt = 0;
  for (char c : s) {
    if (c == '(') {
      opening++;
      cnt++;
    } else {
      closing++;
      cnt--;
    }
    if (cnt < 0) {
      cout << 0 << '\n';
      return;
    }
  }

  if (n & 1 || opening > (n / 2)) {
    cout << 0 << '\n';
    return;
  }
  if (opening == n / 2) {
    cout << 1 << '\n';
    return;
  }

  MathUtils math(n, MOD);

  int ans = math.factorial[n - opening - closing];
  ans = math.multiply(ans, math.multiply(math.inverseFactorial[(n / 2) - opening], math.inverseFactorial[(n / 2) - closing]));
  int sub = math.factorial[n - opening - closing];
  sub = math.multiply(sub, math.multiply(math.inverseFactorial[(n / 2) - opening - 1], math.inverseFactorial[(n / 2)  - closing + 1]));
  ans = math.subtract(ans, sub);

  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int tests = 1;
  while (tests--) {
    solution();
  }

  return 0;
}

// Problem Link: https://cses.fi/problemset/result/13383324/
