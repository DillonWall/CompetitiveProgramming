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


int numIdenticalPairs(vector<int>& nums) {
    // Number of equal nums (if all unique, there are 0)
    // 1, 1, : 1 good pair
    // 1, 1, 1 : 3 good pairs
    // 1, 1, 1, 1 : 6 good pairs
    // 1, 1, 1, 1, 1 : 10 good pairs
    // 1, 1, 1, 1, 1, 1 : 15 good pairs
    // 0, 1 -> 0
    // 2 -> 1
    // 3 -> 3
    // 4 -> 6
    // 5 -> 10
    // 6 -> 15
    // num of unique pairs of x nums
    // y_n = y_n-1 + (n-1)
    // y_n = y_n-2 + (n-2) + (n-1)
    // y_n = y_n-3 + (n-3) + (n-2) + (n-1)
    // y_n = ...
    // y_n = y_n-n + 0 + 1 + 2 + ... + (n-1)
    // y_n = sum(1 to n-1)
    // y_n = (n-1)(n-1 + 1)/2 = (n-1)(n)/2 = (n^2 - n) / 2
    // OP1 - Loop through and store counts, loop through new array and calculate
    // OP2 - Loop through and update num_good on the go (extra unneeded calculations and still need to keep track of how many of the specific int occurred)
    // <= O(2n) = O(n)
    int ans = 0;
    unordered_map<int, int> counts;
    for (auto num : nums) {
        ans += counts[num];
        ++counts[num];
    }
    return ans;
}

void solve() {
    vector<int> nums = {1, 1, 1, 1};
    cout << numIdenticalPairs(nums) << endl;
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