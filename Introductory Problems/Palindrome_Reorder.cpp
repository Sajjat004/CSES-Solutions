/*---------------------------------------
   BISMILLAHIR RAHMANIR RAHIM
   AUTHOR : Md. Sajjat Hossen
   TIME : 19-June,2021 12:38:31 PM
----------------------------------------*/
 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef long long             ll;
typedef long double           ld;
typedef unsigned long long    ull;
typedef pair <int, int>       pii;
typedef pair <ll, ll>         pll;
typedef vector <int>          vi;
typedef vector <ll>           vll;
typedef tree <int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds_set;
typedef tree <int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds_multiset;
 
inline int Int() { int x; scanf("%d", &x); return x; }
inline ll Long() { ll x; scanf("%lld", &x); return x; }
 
int dx[8] = { 0, -1, 0, 1, -1, -1, 1, 1 };
int dy[8] = { -1, 0, 1, 0, -1, 1, 1, -1 };
 
const int N       	= (int) 2e5 + 5;
const int mxN     	= (int) 1e6 + 6;
const int MOD     	= (int) 1e9 + 7;
const int INF     	= (int) 1e9 + 9;
const double EPS	= (double) 1e-9;
 
#define debug(x)    cerr << #x << " = " << x << '\n';
#define all(x)      x.begin(), x.end()
#define szof(x)     (int) x.size()
#define ff          first
#define ss          second
#define pb          push_back
#define mp          make_pair
#define PI          acos(-1.0)
#define TN          typename
#define nl          '\n'
#define Fast_IO     ios_base::sync_with_stdio(false); cin.tie(nullptr);
 
inline int add(int a, int b, int mod) { a += b; return a >= mod ? a - mod : a < 0 ? a + mod : a; }
inline int mult(int a, int b, int mod) { return (ll) a * b % mod; }
 
template <TN T> inline void umin(T &x, T y) { x = x < y ? x : y; }
template <TN T> inline void umax(T &x, T y) { x = x > y ? x : y; }
 
template <TN T> T gcd(T a, T b) { return !b ? a : gcd(b, a % b); }
template <TN T> T lcm(T a, T b) { return a * (b / gcd(a, b)); }
 
int main() {
    Fast_IO
    // clock_t tStart = clock();
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int test = 1, tc = 0;
    while (test--) {
        string s;
        cin >> s;
        int n = szof(s);
        vi frequency(26, 0);
        for (int i = 0; i < n; ++i) frequency[s[i] - 'A']++;
        int oddFreq = 0;
    	for (int i = 0; i < 26; ++i) if (frequency[i] & 1) oddFreq++;
    	if (oddFreq > 1) cout << "NO SOLUTION" << nl;
    	else {
    		string temp1 = "", temp2 = "";
    		for (int i = 0; i < 26; ++i) {
    			if (frequency[i] & 1) {
    				for (int j = 1; j <= frequency[i]; ++j) temp2 += (char)(i + 'A');
    			} else {
    				for (int j = 1; j <= frequency[i] >> 1; ++j) temp1 += (char)(i + 'A');
    			}
    		}
    		string res = temp1 + temp2;
    		reverse(all(temp1));
    		res += temp1;
    		cout << res << nl;
    	}
    }
    // fprintf(stderr, "\nRuntime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    return 0;
}
