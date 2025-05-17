#pragma GCC optimize("O3,unroll-loops")
 
#include<bits/stdc++.h>
using namespace std;
using namespace chrono;
 
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define endl "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
 
// Uncomment the following line to disable debugging for online judge submissions.
// #define ONLINE_JUDGE
 
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x); cerr << "]" << endl
#else
#define debug(x...)
#endif
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef __int128 ell;
 
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
 
// Random Number Generator
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
/*---------------------------------------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);} // Only for prime b
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  // Only for prime m
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);} 
ll __gcd(ll a, ll b) {while (b != 0) {ll temp = b; b = a % b; a = temp;}return a;}
/*--------------------------------------------------------------------------------------------------------------------------*/
bool possible(ll x,ll k,vector<ll>&workloads){
	ll usedWorkers = 1;
	ll currentWorkload = 0;
	for(auto work:workloads){
		if(currentWorkload + work<=x){
			currentWorkload+=work;
		}
		else
		{
			if(usedWorkers == k )
				return false;
			usedWorkers++;
			if(work>x)
				return false;
			currentWorkload = work;
		}
	}
	return true;
	
}
void solve() {
  ll n,k;
  cin>>n>>k;
  vector<ll> nums(n);
  ll l=0,u=0;
  for (ll i = 0; i < n; ++i)
  {
  	cin>>nums[i];
    u+=nums[i];
    l = max(l,nums[i]);
  }
  // search space 1 :
 
  // search space 2 : int l = max_element , int u = sum_of_elements
  // timecomplexity = O(log(searchpace) * time to run
   							// predicate function once)
  
  ll ans = -1 ;// ans is minimised maximum workoad;
  while(l<=u){
  	ll mid = (l+u)/2;
  	if(possible(mid,k,nums))
  		{
  			ans = mid;
  			u = mid-1;
  		}   
  	else
  		l = mid + 1;
  }
  cout<<ans<<endl;
}
 
int main() {
    fastio();
    int tt=1;
    // cin>>tt; 
    while(tt--){ solve();}
    return 0;
}