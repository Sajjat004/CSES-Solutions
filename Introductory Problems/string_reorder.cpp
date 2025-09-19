#include <bits/stdc++.h>
using namespace std;

void run() {
  string s; cin >> s;
  int n = s.size();
  vector<int> cnt(26, 0);
  for (char c : s) cnt[c - 'A']++;

  function<bool()> isPossible = [&]() -> bool {
    int total = 0;
    for (int x : cnt) total += x;
    for (int x : cnt) {
      if (x > (total + 1) / 2) return false;
    }

    return true;
  };

  if (!isPossible()) {
    cout << -1 << '\n';
    return;
  }

  vector<char> res;
  while ((int)res.size() < n) {
    for (int i = 0; i < 26; i++) {
      if (cnt[i] == 0) continue;
      if (!res.empty() && res.back() == (char)('A' + i)) continue;

      cnt[i]--;
      if (isPossible()) {
        res.push_back((char)('A' + i));
        break;
      }
      cnt[i]++;
    }
  }

  for (char c : res) cout << c;
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int tests = 1;
  while (tests--) run();

  return 0;
}
