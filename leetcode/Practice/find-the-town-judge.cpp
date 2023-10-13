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
    int findJudge(int n, vector<vector<int>>& trust) {
        /**
         * The judge will have n trust relations containing their number,
         * so simply use a library(array) with their number (note it will be converted from 0 indexed to 1 indexed)
        */
        int cnts[n];
        memset(cnts, 0, n*sizeof(int));
        for (auto rel : trust) {
            cnts[rel[0]-1] = -1;
            ++cnts[rel[1]-1];
        }
        // for (auto x : cnts) {
        //     cout << x << " ";
        // }
        int judge = -1;
        for (int pers = 0; pers < n; ++pers) {
            if (cnts[pers] == n - 1) {
                if (judge == -1) {
                    judge = pers + 1;
                } else {
                    return -1;
                }
            }
        }
        return judge;
    }
};


void solve() {
    vector<vector<int>> trusts = {{1,3}, {2,3}, {3,1}};
    cout << Solution().findJudge(3, trusts);
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