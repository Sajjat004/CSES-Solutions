#include <bits/stdc++.h>
using namespace std;

// Manacher’s algorithm: returns array of palindrome radii
vector<int> manacher(const string& s) {
  string t = "@";
  for (char c : s) {
    t += string("#") + c;
  }
  t += "#$";

  int n = s.size();
  int m = t.size();
  vector<int> p(m);

  int center = 0, right = 0;
  for (int i = 1; i < m - 1; i++) {
    int mirror = 2 * center - i;
    if (i < right) p[i] = min(right - i, p[mirror]);
    while (t[i + (1 + p[i])] == t[i - (1 + p[i])]) {
      p[i]++;
    }
    if (i + p[i] > right) {
      center = i;
      right = i + p[i];
    }
  }

  return p; // p[i] = radius of palindrome centered at i in transformed string
}

string maxPalindrome(const string& s) {
  vector<int> p = manacher(s);
  int maxLen = 0;
  int center = 0;
  int m = p.size();
  for (int i = 1; i < m - 1; i++) {
    if (p[i] > maxLen) {
      maxLen = p[i];
      center = i;
    }
  }
  int start = (center - maxLen) / 2;

  return s.substr(start, maxLen);
}

void solve() {
  string s;
  cin >> s;

  cout << maxPalindrome(s) << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tests = 1;
  while (tests--) solve();

  return 0;
}
