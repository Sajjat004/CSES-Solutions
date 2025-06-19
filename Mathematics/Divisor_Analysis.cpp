#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int power(int base, int exp, const int mod) {
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

int add(int a, int b, const int mod) { return (a + b) % mod; }
int subtract(int a, int b, const int mod) { return (a - b + mod) % mod; }
int multiply(int a, int b, const int mod) { return 1LL * a * b % mod; }
int divide(int a, int b, const int mod) { return multiply(a, power(b, mod - 2, mod), mod); }

void solution() {
  int n; cin >> n;
  vector<int> x(n);
  vector<int> k(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> k[i];
  }
  
  auto getNOD = [&] () {
    int nod = 1;
    for (int i = 0; i < n; ++i) {
      nod = multiply(nod, k[i] + 1, MOD);
    }

    return nod;
  };

  auto getSOD = [&] () {
    int sod = 1;
    for (int i = 0; i < n; ++i) {
      int numerator = subtract(power(x[i], k[i] + 1, MOD), 1, MOD);
      int denominator = subtract(x[i], 1, MOD);
      int currsod = divide(numerator, denominator, MOD);
      sod = multiply(sod, currsod, MOD);
    }

    return sod;
  };

  auto getPOD = [&] () {
    int pod = 1, nod = 1;
    for (int i = 0; i < n; ++i) {
      pod = power(pod, k[i] + 1, MOD);
      pod = multiply(pod, power(power(x[i], ((1LL * k[i] * (k[i] + 1)) / 2) % (MOD - 1), MOD), nod, MOD), MOD);
      nod = multiply(nod, k[i] + 1, MOD - 1);
    }

    return pod;
  };

  cout << getNOD() << ' ' << getSOD() << ' ' << getPOD() << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int tests = 1;
  while (tests--) {
    solution();
  }

  return 0;
}

// Problem Link: https://cses.fi/problemset/task/2182/
