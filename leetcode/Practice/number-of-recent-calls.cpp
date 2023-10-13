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

class RecentCounter {
public:
    queue<int> reqs;
    RecentCounter() {
    }
    
    /**
     * int ping(int t) Adds a new request at time t, where t represents some time in milliseconds, 
     * and returns the number of requests that has happened in the past 3000 milliseconds (including the new request). 
     * Specifically, return the number of requests that have happened in the inclusive range [t - 3000, t].
     * 
     * It is guaranteed that every call to ping uses a strictly larger value of t than the previous call.
    */
    int ping(int t) {
        if (!reqs.empty() && t - reqs.front() > 3000) {
            reqs.pop();
        }
        reqs.push(t);
        return reqs.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
void solve() {
    RecentCounter* obj = new RecentCounter();
    cout << obj->ping(1);
    cout << obj->ping(100);
    cout << obj->ping(3001);
    cout << obj->ping(3002);
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