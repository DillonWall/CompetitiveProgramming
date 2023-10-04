#include <bits/stdc++.h>

using namespace std;

// Templates that extend ostream
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
// dbg_out will show help debug via submitting
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

// Macros
#define ar array
#define ll long long
#define ld long double
#define sz(x) ((int)x.size())
#define len(x) ((int)x.length())
#define all(a) (a).begin(), (a).end()

// Common constants
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;



void merge(vector<int>& arr, int low, int mid, int high) {
    vector<int> result;
    int i = low, j = mid + 1;

    // traverse both subarrays while both are non empty
    while(i <= mid && j <= high) {
        if(arr[i] <= arr[j]) 
            result.push_back(arr[i++]);
        else
            result.push_back(arr[j++]);
    }

    // append remaining of 1st subarray
    while(i <= mid) {
        result.push_back(arr[i++]);
    }

    // append remaining of 2nd subarray
    while(j <= high) {
        result.push_back(arr[j++]);
    }

    // copy result
    i = low, j = 0;
    while(i <= high) {
        arr[i++] = result[j++];
    }
}

void mergeSort(vector<int>& arr, int low, int high) {
    if(low == high)
        return;
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

void mergeSort(vector<int>& arr) {
    mergeSort(arr, 0, arr.size() - 1);
}


void solve() {
    auto arr = vector<int> {1, 3, 2, 4, 5, 6};
    cout << arr << endl;
    mergeSort(arr);
    cout << arr << endl;
}

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