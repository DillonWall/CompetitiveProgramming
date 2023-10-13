#include <bits/stdc++.h>

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define ar array
#define ll long long
#define ld long double
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * So, if the num differences are odd, then its impossible
 * 101 vs 000 @ x=5 -> 101 --1 011 --1 000
 * 1000 0001 vs 0000 0000 @ x=2 -> X op
 * If distance between next 2 bit flips > x, use x instead
 * 1001 1001 || 
*/
class Solution {
public:
    int minOperations(string s1, string s2, int x) {
        vector<int> a;
        for (int i=0; i<s1.length(); ++i) if (s1[i] != s2[i]) a.push_back(i);

        int sz = a.size();
        if (sz%2 != 0) return -1;

        vector<int> dp(sz+1, 0x7FFFFFFF);
        dp[0] = 0;
        
        for (int i = 1; i <= sz; i++){
            // Update dp[i] based on the minimum cost of making s1 and s2 equal at index a[i-1].
            dp[i] = dp[i - 1] + x;
            if (i >= 2) dp[i] = min(dp[i], dp[i - 2] + 2 * (a[i - 1] - a[i - 2]));
        }
        
        // The final result is half of dp[n] because the cost is calculated for both s1 and s2.
        return dp[sz] / 2;
    }
};

void solve() {
    cout << Solution().minOperations("1100011000", "0101001010", 2) << "\n";
    cout << Solution().minOperations("10110", "00011", 4) << "\n";
    cout << Solution().minOperations("101101", "000000", 6) << "\n";
    cout << Solution().minOperations("10011001", "00000000", 4) << "\n";
}




///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}