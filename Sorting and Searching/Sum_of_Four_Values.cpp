#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int test = 1, tc = 0;
    while (test--) {
        int n; cin >> n;
        int xx; cin >> xx;
        vector<int> v(n, 0);
        for (auto& x : v) cin >> x;
        map<int, vector<pair<int, int>>> m;
        map<int, bool> used;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                m[v[i] + v[j]].push_back({i, j});
                used[v[i] + v[j]] = 1;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int p = xx - v[i] - v[j];
                if (used[p]) {
                    for (auto x : m[p]) {
                        if (x.first != i and x.first != j and x.second != i and x.second != j) {
                            cout << i + 1 << " " << j + 1<< " " << x.first + 1 << " " << x.second + 1<< endl;
                            return 0;
                        }
                    }
                }
            }
        }
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}
