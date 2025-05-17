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

void solve() {
    ll n,k;
    cin>>n>>k;

    vi v(n);
    fl(i,0,n)
    cin>>v[i];

    auto check = [&](ll x)
    {   
        ll cnt = 0;
        fl(i,1,n)
        {   
            // debug(x);
            ll d =  x;
            // debug(d);
             ll t = v[i] - v[i-1];
            //  debug(t);
            if(d != t)
            {   
                if(t>d)
                {   
                    
                    cnt+=(((t+d-1)/d)-1);
                    // cout<<"d"<<" "<<d<<endl;
                    // cout<<cnt<<endl;
                    if(cnt>k)
                    return false;
                }
            }
            
        }
        return cnt<=k;
    };

    ll lo = 1, hi = 1e9;
    ll ans = -1;
    while(lo<=hi)
    {
        ll mid = (lo+hi)/2;
        if(check(mid))
        {
            ans = mid;
            hi = mid-1;
        }
        else
        {
            lo = mid+1;
        }
    }
    cout<<ans<<endl;
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