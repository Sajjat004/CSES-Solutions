#include <bits/stdc++.h>
using namespace std;

bool ask(int y) {
  cout << "? " << y << '\n';
  cout.flush();
  string response; cin >> response;

  return response == "YES";
}

void solution() {
  int left = 1, right = 1e9;
  while (left < right) {
    int mid = left + (right - left) / 2;
    if (ask(mid)) {
      left = mid + 1;
    } else {
      right = mid;
    }
  }

  cout << "! " << left << '\n';
  cout.flush();
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int tests = 1;
  while (tests--) {
    solution();
  }

  return 0;
}

// Problem Link: https://cses.fi/problemset/task/3112/
