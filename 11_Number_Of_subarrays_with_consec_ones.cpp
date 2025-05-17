/* Audhu Billahi Minashaitanir Rajeem
Bismillahir Rahmanir Raheem */
#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define endl "\n"
#define vi vector<ll>
#define vp vector<pair<ll, ll>>
#define fl(i, a, n) for (ll i = (a); i < (n); i++)
#define flr(i, a, n) for (ll i = (a); i >= (n); i--)
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define set_bits __builtin_popcountll

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef __int128 ell;

#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x); cerr << "]" << endl
#else
#define debug(x...)
#endif

void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V> void _print(pair<T, V> p);
template <class T> void _print(vector<T> v);
template <class T> void _print(set<T> v);
template <class T, class V> void _print(map<T, V> v);
template <class T> void _print(multiset<T> v);

template <class T, class V> void _print(pair<T, V> p) { cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}"; }
template <class T> void _print(vector<T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(set<T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(multiset<T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template <class T, class V> void _print(map<T, V> v) { cerr << "[ "; for (auto i : v) { _print(i); cerr << " "; } cerr << "]"; }
ll n,k;
vector<ll> arr(100100);
vector<ll>  p(100100);
ll numzero(ll l, ll r)
{
    return  (p[r] - (l>0?p[l-1]:0));
}
bool check(ll st,ll x)
{
    return numzero(st,x)<=k;
}
void solve() {
    cin>>n>>k;
    fl(i,0,n)
    {
        cin>>arr[i];
        p[i] = arr[i];
        if(i)   // could have flipped the ones and then calc the pref
        p[i]+=p[i-1];
    }
    // zeros matters
    ll res = 0 ;
    ll total = 0;
    for(ll st =0 ;st<n;st++)
    {
        ll lo = st;
        ll hi = n-1;
        ll ans = st-1 ;// important edge case here [1 0 1 0 1 ] n=5,k=0
        while(lo<=hi)
        {
            ll mid = (lo+hi)/2;
            if(check(st,mid))
            {
                ans = mid;
                lo  = mid + 1;
            }
            else
                hi = mid - 1; 
        }
        // res+=(ans - st + 1);
        total = max(total , (ans - (st - 1)));
    }

}

int main() {
    fastio();
    int tt; 
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}