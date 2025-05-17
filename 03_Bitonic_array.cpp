#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,x;
ll arr[100100];
bool check(int mid)
{   
   if(mid==n-1) return 1;
   if(arr[mid]>arr[mid+1]) // for upper_bound use arr[mid]>x
   return true;
   else return false; 
}
int main()
{
    cin>>n;
    for (ll i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cin>>x;
//  lower_bound
    ll lo = 0 ;
    ll hi = n-1;
    ll ans = -1; // default doesn't matter here as in bitonic array
    // the n-1 is set to 1 by default to it doesn't matter what to put n;
    while(lo<=hi)
    {
        ll mid = (hi+lo)/2; // lo  + (hi-lo) / 2
        if(check(mid)==1)
        {
            ans = mid;
            hi = mid-1;
        }
        else
            lo = mid+1;
    }
    cout<<arr[ans]<<endl;
}