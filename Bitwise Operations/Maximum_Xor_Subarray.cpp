#include <bits/stdc++.h>
using namespace std;

class Trie {
  struct TrieNode {
    TrieNode* next[2] = {nullptr, nullptr};
  };
  TrieNode* root;

public:
  Trie() {
    root = new TrieNode();
  }

  void insert(int num) {
    TrieNode* currNode = root;
    for (int i = 30; i >= 0; --i) {
      int bit = (num >> i) & 1;
      if (!currNode->next[bit]) {
        currNode->next[bit] = new TrieNode();
      }
      currNode = currNode->next[bit];
    }
  }

  int findMaxXor(int num) {
    TrieNode* currNode = root;
    int maxXor = 0;
    for (int i = 30; i >= 0; --i) {
      int bit = (num >> i) & 1;
      if (currNode->next[1 - bit]) {
        maxXor |= (1 << i);
        currNode = currNode->next[1 - bit];
      } else {
        currNode = currNode->next[bit];
      }
    }

    return maxXor;
  }
};

void solution() {
  int n; cin >> n;
  vector<int> nums(n);
  for (int& num : nums) cin >> num;

  Trie trie;
  int XOR = 0;
  int maxXor = 0;
  trie.insert(0);
  for (int num : nums) {
    XOR ^= num;
    maxXor = max(maxXor, trie.findMaxXor(XOR));
    trie.insert(XOR);
  }

  cout << maxXor << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  solution();

  return 0;
}

// Problem Link: https://cses.fi/problemset/task/1655/
