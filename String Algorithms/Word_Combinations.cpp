#include <bits/stdc++.h>
using namespace std;

using ll  = long long;
using vll = vector<ll>;
using vi  = vector<int>;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

const int N   = (int) 1e6 + 5;
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9 + 9;

#define nl      '\n'
#define ff      first
#define ss      second
#define szof(x) (int) x.size()
#define all(x)  x.begin(), x.end()

int dp[5005];

class Trie {
  vector<vector<int>> node;
  vector<int> cntPath;
  int state = 0;
public:
  Trie() {
    node.resize(N, vector<int>(26, -1));
    cntPath.resize(N, 0);
    state = 0;
  }
  void add(string& s) {
    int cur = 0;
    for (int i = 0; i < (int) s.size(); ++i) {
      int id = s[i] - 'a';
      if (node[cur][id] == -1) node[cur][id] = ++state;
      cur = node[cur][id];
    }
    cntPath[cur]++;
  }
  int search(string& s, int idx) {
    int cur = 0;
    int ans = 0;
    for (int i = idx; i < (int) s.size(); ++i) {
      int id = s[i] - 'a';
      if (node[cur][id] == -1) return ans;
      cur = node[cur][id];
      if (cntPath[cur]) {
        ans += dp[i + 1];
        ans %= MOD;
      }
    }
    return ans;
  }
};

int main() {
  // freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(false); cin.tie(0);
  int test = 1, tc = 0;
  while (test--) {
    string s; cin >> s;
    int q; cin >> q;
    Trie trie;
    while (q--) {
      string t; cin >> t;
      trie.add(t);
    }
    dp[szof(s)] = 1;
    for (int i = szof(s) - 1; i >= 0; --i) {
      dp[i] = trie.search(s, i);
    }
    cout << dp[0] << nl;
  }
  return 0;
}