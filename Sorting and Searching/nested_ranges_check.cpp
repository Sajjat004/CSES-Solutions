#include <bits/stdc++.h>
using namespace std;
 
struct Range {
  int left, right, idx;
  Range(int l, int r, int i) : left(l), right(r), idx(i) {}
 
  bool operator<(const Range& rhs) const {
    return left == rhs.left ? right > rhs.right : left < rhs.left;
  }
};
 
void run() {
  int n; cin >> n;
  vector<Range> ranges;
  for (int i = 0; i < n; ++i) {
    int l, r; cin >> l >> r;
    ranges.emplace_back(l, r, i);
  }
  sort(ranges.begin(), ranges.end());
 
  vector<bool> contains(n);
  int minEnd = INT_MAX;
  for (int i = n - 1; i >= 0; --i) {
    auto [l, r, idx] = ranges[i];
    if (r >= minEnd) contains[idx] = true;
    minEnd = min(minEnd, r);
  }
 
  vector<bool> contained(n);
  int maxEnd = INT_MIN;
  for (int i = 0; i < n; ++i) {
    auto [l, r, idx] = ranges[i];
    if (r <= maxEnd) contained[idx] = true;
    maxEnd = max(maxEnd, r);
  }
 
  for (int i = 0; i < n; ++i) cout << contains[i] << ' ';
  cout << '\n';
  for (int i = 0; i < n; ++i) cout << contained[i] << ' ';
  cout << '\n';
 
}
 
int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
 
  int tests = 1;
  while (tests--) run();
 
  return 0;
}
