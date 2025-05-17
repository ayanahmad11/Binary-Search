#include <bits/stdc++.h>
using namespace std;
#define int long long
 
int n, t;
int arr[200100];
 
bool check(int mid) {
    int total_product = 0;
    for (int i = 0; i < n; i++) {
        total_product += ((mid )/ arr[i]);
        if (total_product >= t) return true; // prevent overflow
    }
    return (total_product>=t);
}
 
void solve() {
    cin >> n >> t;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
 
    int lo = 0;
    // int hi = 1e18+1; // FIXED
    int max_arr = *max_element(arr, arr + n);
    int  hi = (max_arr*1LL*t);
    int ans = -1;
 
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (check(mid)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
 
    cout << ans << endl;
}
 
int32_t main() {
    int tt = 1;
    while (tt--) {
        solve();
    }
    return 0;
}
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long

// int n, t;
// int arr[200100];

// bool check(int mid) {
//     int total_product = 0;
//     for (int i = 0; i < n; i++) {
//         total_product += (mid / arr[i]);
//         if(total_product>=t) return true;
//     }
//     return total_product >= t;
// }

// void solve() {
//     cin >> n >> t;
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }

//     int lo = 1;
//     int max_arr = *max_element(arr, arr + n);
    
//     // Calculate the upper bound hi dynamically based on max(arr) and t
//     int hi = max_arr * t;
    
//     // Ensure that hi does not exceed the range of long long
//     if (hi > 1e18) {
//         hi = 1e18;  // Set an upper bound for hi to avoid overflow
//     }

//     int ans = -1;

//     while (lo <= hi) {
//         int mid = lo + (hi - lo) / 2;
//         if (check(mid)) {
//             ans = mid;
//             hi = mid - 1;
//         } else {
//             lo = mid + 1;
//         }
//     }

//     cout << ans << endl;
// }

// int32_t main() {
//     int tt = 1;
//     while (tt--) {
//         solve();
//     }
//     return 0;
// }
