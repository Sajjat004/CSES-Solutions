/*--------------------------------
    bismillahir rahmanir rahim
---------------------------------*/
 
#include <bits/stdc++.h>
using namespace std;
 
typedef long long          ll;
typedef long double        ld;
typedef unsigned long long ull;
typedef pair <int, int>    pii;
typedef pair <ll, ll>      pll;
typedef vector <int>       vi;
typedef vector <ll>        vll;
 
inline int Int() { int x; scanf("%d", &x); return x; }
inline ll Long() { ll x; scanf("%lld", &x); return x; }
 
int dx[8] = { 0, -1, 0, 1, -1, -1, 1, 1 };
int dy[8] = { -1, 0, 1, 0, -1, 1, 1, -1 };
 
const int N      = (int) 2e5 + 5;
const int mxN    = (int) 1e6 + 6;
const int MOD    = (int) 1e9 + 7;
const int INF    = (int) 1e9 + 9;
const double EPS = (double) 1e-9;
 
#define debug(x) cerr << #x << " = " << x << '\n';
#define all(x)   x.begin(), x.end()
#define szof(x)  (int) x.size()
#define ff       first
#define ss       second
#define pb       push_back
#define PI       acos(-1.0)
#define nl       '\n'
#define Fast_IO  ios_base::sync_with_stdio(false); cin.tie(nullptr);
 
inline int add(int a, int b, int mod) {
    a += b; return a >= mod ? a - mod : a < 0 ? a + mod : a; }
inline int mult(int a, int b, int mod) { return (ll) a * b % mod; }
 
template <typename T> inline void umin(T &x, T y) { x = x < y ? x : y; }
template <typename T> inline void umax(T &x, T y) { x = x > y ? x : y; }
 
template <typename T> T gcd(T a, T b) { return !b ? a : gcd(b, a % b); }
template <typename T> T lcm(T a, T b) { return a * (b / gcd(a, b)); }
 
#define error(...) __f(#__VA_ARGS__, __VA_ARGS__);
template < typename Arg1 >
void __f(const char* name, Arg1&& arg1){
    cerr << name << " = " << arg1 << std::endl;
}
template < typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names+1, ',');
    cerr.write(names, comma - names) << " = " << arg1 <<" ";
    __f(comma+1, args...);
}
 
// ----------------------- solution starts from here ----------------------- //
 
int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    // Fast_IO
    int test = 1, tc = 0;
    while (test--) {
        int n = Int(), x = Int();
        vector<pii> v;
        for (int i = 1; i <= n; ++i) {
            int x = Int();
            v.pb({x, i});
        }
        sort(all(v));
        for (int i = 0; i < n - 1; ++i) {
            int l = i + 1, r = n - 1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if ((v[i].ff + v[mid].ff) == x) {
                    printf("%d %d\n", v[i].ss, v[mid].ss);
                    return 0;
                } else if ((v[i].ff + v[mid].ff) < x) l = mid + 1;
                else r = mid - 1; 
            }
        }
        printf("IMPOSSIBLE\n");
    }
    return 0;
}
