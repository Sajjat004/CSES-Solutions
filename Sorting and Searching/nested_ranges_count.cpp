#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template<typename T> using ordMSet = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

  vector<int> contains(n);
  ordMSet<int> ends;
  for (int i = n - 1; i >= 0; --i) {
    int smaller = ends.order_of_key(ranges[i].right + 1);
    contains[ranges[i].idx] = smaller;
    ends.insert(ranges[i].right);
  }

  vector<int> contained(n);
  ends.clear();
  for (int i = 0; i < n; ++i) {
    int smaller = ends.order_of_key(ranges[i].right);
    contained[ranges[i].idx] = ends.size() - smaller;
    ends.insert(ranges[i].right);
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
