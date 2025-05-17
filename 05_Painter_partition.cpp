/* Audhu Billahi Minashaitanir Rajeem
Bismillahir Rahmanir Raheem */
#include <bits/stdc++.h>
#define int long long 
using namespace std;

int n,k;
int arr[200100];
bool check(int mid)
{   
    int last_painter_time_left = 0LL;
    int num_painter_spawned = 0LL;

    for(int i=0;i<n;i++)
    {
        if(last_painter_time_left>=arr[i])
        {
            last_painter_time_left-=arr[i];
        }
        else
        {
            num_painter_spawned++;
            if(num_painter_spawned > k)
            return false;

            last_painter_time_left = mid;
            if(last_painter_time_left>=arr[i])
            {
                last_painter_time_left-=arr[i];
            }
            else  // [1,6] mid = 5;  not possible in 5 seconds
            {
            return false; // failure;
            }
        }
    }
    return true;
}
void solve() {
    cin>>n>>k;
    int sum = 0LL;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    int lo = 0LL, hi = sum, ans = -1; 
    while(lo<=hi)
    {
        int mid = (lo+hi)/2LL;
            if(check(mid))
            {
                ans = mid;
                hi = mid-1;
            }
            else
                lo = mid+1;
    }
    cout<<ans<<endl;
}

int32_t main() {
    
    int tt=1; 
    // cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}