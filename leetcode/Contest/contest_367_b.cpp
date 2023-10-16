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


class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int l = 0, r = -1;
        int n = s.size();
        int cnt = 0;
        int best_len = n;
        int best_l = -1; int best_r = -1;
        while (l < n && s[l] == '0') {
            ++l;
            ++r;
        }
        while (n > 0 && s[n - 1] == '0') --n;
        while (r < n) {
            ++r;
            if (s[r] == '1') {
                ++cnt;
                if (cnt == k) { //00010000110001
                    // We found one match, record if needed
                    if (r - l < best_len) {                        
                        best_len = r - l;
                        best_l = l;
                        best_r = r;
                    } else if (r - l == best_len) {
                        // Check if lexigrafically better
                        for (int i = 0; i < best_len; ++i) {
                            if (s[best_l + i] < s[l + i]) {
                                break;
                            } else if (s[best_l + i] > s[l + i]) {
                                best_l = l;
                                best_r = r;
                                break;
                            }
                        }
                    }
                    // March left to next 1 (will at least reach current r)
                    while (l < r && s[++l] != '1');
                    --cnt;
                }
            }
        }
        if (best_l == -1) return "";
        return s.substr(best_l, best_r - best_l + 1);
    }
};

void solve() {

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