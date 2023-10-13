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
// const ll INF = 1e9;
const ld EPS = 1e-9;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class KthLargest {
public:
    // multiset<int, greater<int>> ms;
    // multiset<int, greater<int>>::iterator itr;
    // int k;
    // KthLargest(int k, vector<int>& nums) {
    //     for (auto num: nums) {
    //         ms.insert(num);
    //     }
    //     itr = ms.begin();
    //     for (int i=0; i < k-1; ++i) {
    //         ++itr;
    //     }
    //     this->k = k;
    // }
    
    // int add(int val) {
    //     ms.insert(val);        
    //     if (ms.size() == k) {
    //         itr = ms.end();
    //         --itr;
    //         return *itr;
    //     }
    //     if (val > *itr) {
    //         --itr;
    //     }
    //     return *itr;
    // }

    priority_queue<int, vector<int>, greater<int>> pq;
    const int N_INF = -1e5;
    KthLargest(int k, vector<int>& nums) {
        for (auto num: nums) {
            pq.push(num);
        }
        
        for (int i=0; i<pq.size(); ++i) {
            cout << pq.top() << ", ";
            pq.pop();
        }
        cout << "\n";
        // pq.push(N_INF);
        // for (int i=0; i<pq.size()-k; ++i) {
        //     pq.pop();
        // }
    }
    
    int add(int val) {
        pq.push(val);
        pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
void solve() {
    int k = 3; 
    vector<int> nums = {4, 5, 8, 2};
    KthLargest kthLargest = KthLargest(k, nums);
    // cout << kthLargest.add(3) << "\n";   // return 4
    // cout << kthLargest.add(5) << "\n";   // return 5
    // cout << kthLargest.add(10) << "\n";  // return 5
    // cout << kthLargest.add(9) << "\n";   // return 8
    // cout << kthLargest.add(4) << "\n";   // return 8
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