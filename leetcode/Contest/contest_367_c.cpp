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
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        // Base cases
        if (nums.size() < indexDifference) return {-1,-1};
        if (nums.size() >= 1 && indexDifference == 0 && valueDifference == 0) return {0,0};
        if (nums.size() == 1) return {-1,-1};
        // Create sorted map of values with their lowest and highest indecies
        map<int, pair<int,int>, less<int>> values;
        for (int i=0; i<nums.size(); i++) {
            if (values.count(nums[i]) == 0) {
                values[nums[i]] = {i,i};
            } else if (i < values[nums[i]].first) {
                values[nums[i]].first = i;
            } else if (i > values[nums[i]].second) {
                values[nums[i]].second = i;
            }
        }
        cout << values << endl;
        // 2 Pointers iterate the map
        auto l = values.begin();
        auto r = values.begin();
        while (++r != values.end()) {
            while ((*r).first - (*l).first >= valueDifference) {
                cout << *l << " " << *r << endl;
                if ((*r).second.second - (*l).second.first >= indexDifference) return {(*r).second.second, (*l).second.first};
                if ((*l).second.second - (*r).second.first >= indexDifference) return {(*r).second.first, (*l).second.second};
                ++l;
            }
        }
        return {-1,-1};        
    }
};


void solve() {
    vector<int> nums = {1,3,4,4};
    int indexDifference = 2;
    int valueDifference = 2;
    Solution s;
    vector<int> ans = s.findIndices(nums, indexDifference, valueDifference);
    cout << ans << endl;
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