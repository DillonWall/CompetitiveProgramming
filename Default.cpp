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


void merge2desc(vector<int>& arr, int low, int mid, int high) {
    vector<int> result;
    int i = low, j = mid + 2;

    // traverse both subarrays while both are non empty
    while(i <= mid && j <= high) {
        if(arr[i] >= arr[j]) {
            result.push_back(arr[i]);
            i += 2;
        } else {
            result.push_back(arr[j]);
            j += 2;
        }
    }

    // append remaining of 1st subarray
    while(i <= mid) {
        result.push_back(arr[i]);
        i += 2;
    }

    // append remaining of 2nd subarray
    while(j <= high) {
        result.push_back(arr[j]);
        j += 2;
    }

    // copy result
    i = low, j = 0;
    while(i <= high) {
        arr[i] = result[j++];
        i += 2;
    }
}

void merge2(vector<int>& arr, int low, int mid, int high) {
    vector<int> result;
    int i = low, j = mid + 2;

    // traverse both subarrays while both are non empty
    while(i <= mid && j <= high) {
        if(arr[i] <= arr[j]) { 
            result.push_back(arr[i]);
            i += 2;
        } else {
            result.push_back(arr[j]);
            j += 2;
        }
    }

    // append remaining of 1st subarray
    while(i <= mid) {
        result.push_back(arr[i]);
        i += 2;
    }

    // append remaining of 2nd subarray
    while(j <= high) {
        result.push_back(arr[j]);
        j += 2;
    }

    // copy result
    i = low, j = 0;
    while(i <= high) {
        arr[i] = result[j++];
        i += 2;
    }
}

void mergeSortEven(vector<int>& arr, int low, int high) {
    if(low == high)
        return;
    int mid = (low + high) / 2;
    int evenMid = mid - (mid%2); // If odd, subs 1 to mid to make it even
    mergeSortEven(arr, low, evenMid);
    mergeSortEven(arr, evenMid + 2, high);
    merge2(arr, low, evenMid, high);
}

void mergeSortOdd(vector<int>& arr, int low, int high) {
    if(low == high)
        return;
    int mid = (low + high) / 2;
    int oddMid = mid - ((mid+1)%2); // If even, subs 1 to mid to make it odd
    mergeSortOdd(arr, low, oddMid);
    mergeSortOdd(arr, oddMid + 2, high);
    merge2desc(arr, low, oddMid, high);
}

void mergeSort(vector<int>& arr) {
    int end = arr.size() - 1;
    int evenEnd = end - (end%2); // If odd, subs 1
    int oddEnd = end - ((end+1)%2); // If even, subs 1
    cout << evenEnd << " " << oddEnd << "\n";
    mergeSortEven(arr, 0, evenEnd);
    mergeSortOdd(arr, 1, oddEnd);
}

vector<int> sortEvenOdd(vector<int>& nums) {
    if (nums.size() > 2) { // No need to sort if too small
        mergeSort(nums);
    }
    return nums;
}

void solve() {
    vector<int> arr = {5,2,6,8,4,3,1};
    cout << "Before Sorting: ";
    for (auto x : arr) {
        cout << x << " ";
    }
    cout << "\n";
    arr = sortEvenOdd(arr);
    cout << "After Sorting: ";
    for (auto x : arr) {
        cout << x << " ";
    }
    cout << "\n";
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