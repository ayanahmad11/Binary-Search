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
    ll n, k;
    cin >> n >> k;
    vi v(n), pref(n);
    fl(i, 0, n) {
        cin >> v[i];
        pref[i] = v[i] + (i > 0 ? pref[i - 1] : 0);
    }

    auto check = [&](ll x) {
        for (ll i = 0; i + x <= n; i++) {
            ll ones = pref[i + x - 1] - (i == 0 ? 0 : pref[i - 1]);
            ll zeros = x - ones;
            if (zeros <= k) return true;
        }
        return false;
    };

    ll ans = 0, lo = 0, hi = n;
    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        if (check(mid)) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    cout << ans << endl;
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

// /* Audhu Billahi Minashaitanir Rajeem
// Bismillahir Rahmanir Raheem */
// #pragma GCC optimize("O3,unroll-loops")

// #include <bits/stdc++.h>
// using namespace std;
// using namespace chrono;

// #define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
// #define MOD 1000000007
// #define MOD1 998244353
// #define INF 1e18
// #define endl "\n"
// #define vi vector<ll>
// #define vp vector<pair<ll, ll>>
// #define fl(i, a, n) for (ll i = (a); i < (n); i++)
// #define flr(i, a, n) for (ll i = (a); i >= (n); i--)
// #define pb push_back
// #define ppb pop_back
// #define mp make_pair
// #define ff first
// #define ss second
// #define PI 3.141592653589793238462
// #define sz(x) ((int)(x).size())
// #define all(x) (x).begin(), (x).end()
// #define set_bits __builtin_popcountll

// typedef long long ll;
// typedef unsigned long long ull;
// typedef long double lld;
// typedef __int128 ell;

// #ifndef ONLINE_JUDGE
// #define debug(x...) cerr << "[" << #x << "] = ["; _print(x); cerr << "]" << endl
// #else
// #define debug(x...)
// #endif

// void _print(ll t) { cerr << t; }
// void _print(int t) { cerr << t; }
// void _print(string t) { cerr << t; }
// void _print(char t) { cerr << t; }
// void _print(lld t) { cerr << t; }
// void _print(double t) { cerr << t; }
// void _print(ull t) { cerr << t; }

// template <class T, class V> void _print(pair<T, V> p);
// template <class T> void _print(vector<T> v);
// template <class T> void _print(set<T> v);
// template <class T, class V> void _print(map<T, V> v);
// template <class T> void _print(multiset<T> v);

// template <class T, class V> void _print(pair<T, V> p) { cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}"; }
// template <class T> void _print(vector<T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
// template <class T> void _print(set<T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
// template <class T> void _print(multiset<T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
// template <class T, class V> void _print(map<T, V> v) { cerr << "[ "; for (auto i : v) { _print(i); cerr << " "; } cerr << "]"; }

// void solve() {
//     ll n,k;
//     cin>>n>>k;

//     vi v(n),pref;
//     ll sum = 0 ;
//     fl(i,0,n)
//     {
//         cin>>v[i];
//         sum+=v[i];
//         pref.pb(sum);
//     }
//     // debug(v);
//     // debug(pref);
//     auto check=[&](ll x)
//     {   ll cnt = 0 ;
//         ll zeros = (x - pref[x-1] );
//         return zeros<=k;
//         // debug(x);
//         // debug(zeros);
//         for(ll i=1;i+x<n;i++)
//         {
//             ll zeros = (x - pref[i+x-1] - pref[i-1]);   
//             return zeros<=k;
//         }
//         return cnt<=k;
//     };
//     ll ans = -1;
//     ll lo = 0 , hi = n; 
//     while(lo<=hi)
//     {
//         ll mid = (lo+hi)/2;
//         if(check(mid))
//         {
//             ans = mid;
//             lo = mid+1;
//         }
//         else
//         {
//             hi = mid-1;
//         }
//     }
//     cout<<ans<<endl;
// }

// int main() {
//     fastio();
//     int tt; 
//     cin >> tt;
//     while (tt--) {
//         solve();
//     }
//     return 0;
// }