#include <bits/stdc++.h>
using namespace std;

class MathUtils {
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

public:
  MathUtils(int n, const int mod) : n(n), mod(mod) {
    buildFactorial(n);
  }

  int ncr(int n, int k) {
    if (k < 0 || k > n) return 0;
    return 1LL * factorial[n] * inverseFactorial[k] % mod * inverseFactorial[n - k] % mod;
  }

  int getInverseMod(int k) {
    return power(k, mod - 2);
  }
};

void solution() {
  int n; cin >> n;
  if (n & 1) {
    cout << "0\n";
    return;
  }

  const int mod = 1e9 + 7;
  MathUtils math(n, mod);
  int ans = math.ncr(n, n / 2);
  ans = 1LL * ans * math.getInverseMod((n / 2) + 1) % mod;
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

// Problem Link: https://cses.fi/problemset/task/2064/
