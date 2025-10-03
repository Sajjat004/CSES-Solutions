#include <bits/stdc++.h>
using namespace std;

const int N = 1009;
const int MOD = 1e9 + 7;
int memo[N][1 << 10];
int n, m;

void generateMaks(int p, int curr, int next, vector<int>& nextMasks) {
  if (p == n) {
    nextMasks.push_back(next);
    return;
  }

  if ((curr >> p) & 1) {
    generateMaks(p + 1, curr, next, nextMasks);
    return;
  }
  generateMaks(p + 1, curr | (1 << p), next | (1 << p), nextMasks);
  if ((p + 1) < n && !((curr >> (p + 1)) & 1))
    generateMaks(p + 2, (curr | (1 << p)) | (1 << (p + 1)), next, nextMasks);
}

int dp(int pos, int mask) {
  if (pos == m) return mask == 0;
  if (memo[pos][mask] != -1) return memo[pos][mask];

  int res = 0;
  vector<int> nextMasks;
  generateMaks(0, mask, 0, nextMasks);
  for (auto next : nextMasks) {
    res += dp(pos + 1, next);
    if (res >= MOD) res -= MOD;
  }

  return memo[pos][mask] = res;
}

void run() {
  cin >> n >> m;
  memset(memo, -1, sizeof memo);

  cout << dp(0, 0) << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int tests = 1;
  while (tests--) run();

  return 0;
}
