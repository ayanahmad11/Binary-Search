// Write your code here
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, q;
ll arr[100100];

// Function to find the peak in a bitonic array
bool check(int mid) {   
   if(mid == n-1) return true;
   return arr[mid] > arr[mid+1];
}

// Binary search on decreasing part
int binarySearchDecreasing(ll x, ll l, ll r) {
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (arr[mid] == x) return mid;
        else if (arr[mid] < x) r = mid - 1;
        else l = mid + 1;
    }
    return -1;
}

int main() {
    int tt;
    cin >> tt;
    while(tt--) {
        cin >> n >> q;

        for (ll i = 0; i < n; i++) {
            cin >> arr[i];
        }

        // Find peak
        ll lo = 0, hi = n-1, ans = -1;
        while (lo <= hi) {
            ll mid = (lo + hi) / 2;
            if (check(mid)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        ll peak = ans;
        // cout << "peak: " << peak << endl;

        while (q--) {
            ll x;
            cin >> x;

            int index1 = -1, index2 = -1;

            // Search in increasing part (0 to peak)
            auto it1 = lower_bound(arr, arr + peak + 1, x);
            if (it1 != arr + peak + 1 && *it1 == x)
                index1 = it1 - arr;

            // Search in decreasing part (peak+1 to n-1) using custom binary search
            index2 = binarySearchDecreasing(x, peak + 1, n - 1);
            if(index1!=-1)
            {
                cout<<index1+1<<" ";
            }
            if(index2!=-1)
            cout<<index2+1<<" ";
            cout<<endl;
        }
    }
}

// #include<bits/stdc++.h>
// using namespace std;
// using ll = long long;

// ll n, q;
// ll arr[100100];

// // Function to find the peak in a bitonic array
// bool check(int mid) {   
//    if(mid == n-1) return true;
//    return arr[mid] > arr[mid+1];
// }

// // Binary search on decreasing part
// int binarySearchDecreasing(ll x, ll l, ll r) {
//     while (l <= r) {
//         ll mid = (l + r) / 2;
//         if (arr[mid] == x) return mid;
//         else if (arr[mid] < x) r = mid - 1;
//         else l = mid + 1;
//     }
//     return -1;
// }

// int main() {
//     int tt;
//     cin >> tt;
//     while(tt--) {
//         cin >> n >> q;

//         for (ll i = 0; i < n; i++) {
//             cin >> arr[i];
//         }

//         // Find peak
//         ll lo = 0, hi = n-1, ans = -1;
//         while (lo <= hi) {
//             ll mid = (lo + hi) / 2;
//             if (check(mid)) {
//                 ans = mid;
//                 hi = mid - 1;
//             } else {
//                 lo = mid + 1;
//             }
//         }
//         ll peak = ans;
//         cout << "peak: " << peak << endl;

//         while (q--) {
//             ll x;
//             cin >> x;

//             int index = -1;
//             int index2 = -1;
//             // Search in increasing part
//             auto it1 = lower_bound(arr, arr + peak + 1, x);
//             if (it1 != arr + peak + 1 && *it1 == x)
//                 index = it1 - arr;
//             sort(arr+peak+1,arr+n);
//             auto it2 = lower_bound(arr+peak+1, arr+n, x);
//             if (it2 != arr + n  && *it2 == x)
//                 index2 = it2 - arr;

//             cout << (index != -1 ? index : -1)<<" " ;
//             cout << (index2 != -1 ? index2 : -1)<<endl;
//         }
//     }
// }

// #include<bits/stdc++.h>
// using namespace std;
// using ll = long long;
// ll n,x;
// ll arr[100100];
// bool check(int mid)
// {   
//    if(mid==n-1) return 1;
//    if(arr[mid]>arr[mid+1]) // for upper_bound use arr[mid]>x
//    return true;
//    else return false; 
// }
// int main()
// {   int tt;
//     cin>>tt;
//     int q;
//     while(tt--)
//     {
//         cin>>n>>q;
//         int q;
//     for (ll i = 0; i < n; i++)
//     {
//         cin>>arr[i];
//     }
    
//         // cin>>x;
//     //  lower_bound
//         ll lo = 0 ;
//         ll hi = n-1;
//         ll ans = -1; // default doesn't matter here as in bitonic array
//         // the n-1 is set to 1 by default to it doesn't matter what to put n;
//         while(lo<=hi)
//         {
//             ll mid = (hi+lo)/2; // lo  + (hi-lo) / 2
//             if(check(mid)==1)
//             {
//                 ans = mid;
//                 hi = mid-1;
//             }
//             else
//                 lo = mid+1;
//         }
//         ll peak = ans;
//         cout<<"peak:"<<" "<<peak<<endl;
        
//         while(q--)
//         {
//             ll x;
//             cin>>x;
//             // ll ans1 = -1,ans2=-1;
//             auto ans1 = lower_bound(arr,arr+peak,x);
//             auto ans2 = lower_bound(arr+peak+1,arr+n,x);
//             // cout<<ans1<<" "<<ans2<<endl;

//         }
    
//     }
// }