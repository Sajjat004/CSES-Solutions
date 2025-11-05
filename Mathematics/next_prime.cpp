#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> primes;
void sieve(int n) {
  vector<bool> isPrime(n + 1, true);
  isPrime[0] = isPrime[1] = false;
  for (int i = 2; i * i <= n; i++) {
    if (isPrime[i]) {
      for (int j = i * i; j <= n; j += i) {
        isPrime[j] = false;
      }
    }
  }

  for (int i = 2; i <= n; i++) {
    if (isPrime[i]) primes.push_back(i);
  }
}

ll nextPrime(ll n) {
  ll L = n + 1, R = n + 2000;
  vector<bool> isPrime(R - L + 1, true);
  for (int p : primes) {
    if (1LL * p * p > R) break;
    ll start = max(1LL * p * p, (L + p - 1) / p * p);
    for (ll j = start; j <= R; j += p) {
      isPrime[j - L] = false;
    }
  }
  if (L == 1) isPrime[0] = false;
  for (ll i = L; i <= R; i++) {
    if (isPrime[i - L]) return i;
  }

  return -1;
}

void solve() {
  ll n;
  cin >> n;

  cout << nextPrime(n) << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  const int N = 5e6;
  sieve(N);

  int tests = 1;
  cin >> tests;
  while (tests--) solve();

  return 0;
}
