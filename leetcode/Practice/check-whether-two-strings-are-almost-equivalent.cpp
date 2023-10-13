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

bool checkAlmostEquivalent(string word1, string word2) {
    // Keep a hashmap of letters and their counts from word1 and word2
    // Add if in word 1, and sub if in word 2
    // If the hashmap has any elements above 3 or below -3, it is not almost equiv
    // O(n) time because the hash map will never be more than 26 elements long (const time)
    unordered_map<char, int> counts;
    for (int ii = 0; ii < word1.length(); ++ii) {
        ++counts[word1[ii]];
        --counts[word2[ii]];
    }
    for (auto c : counts) {
        if (c.second > 3 || c.second < -3) {
            return false;
        }
    }
    return true;
}


void solve() {
    cout << checkAlmostEquivalent("aaaa", "bccb") << endl;
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