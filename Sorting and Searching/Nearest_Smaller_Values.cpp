#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int test = 1, tc = 0;
    while (test--) {
        int n; cin >> n;
        stack<pair<int, int>> st;
        for (int i = 1; i <= n; ++i) {
            int x; cin >> x;
            while (!st.empty() and st.top().first >= x) st.pop();
            if (st.empty()) cout << 0 << " ";
            else cout << st.top().second << " ";
            st.push({x, i});
        }
        cout << endl;
    }
    return 0;
}
