/**
 * @file code.cpp
 * @author udtha kouwa
 * @created:
 */
 
#include <bits/stdc++.h>
#include <ctime>
#include <list>
 
 
  
 
using  namespace  std;
using namespace std::chrono;
#pragma GCC optimization ("O3") //dont know 
#pragma GCC optimization ("unroll-loops") //dont know 
#define ll long long
#define ull unsigned long long
#define pb push_back
#define bahut_tez  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define ss second
#define ff first
#define pi pair<int,int>
#define pll pair<ll,ll> 
#define vi vector<int>
#define vll vector<ll>
 
#ifndef ONLINE_JUDGE
#define debug(x) cerr<<#x<<"\n";_print(x);cerr<<endl;
#else
#define debug(x)
#endif
 
//debugging
//*********************************************************************
void _print(pair<int,int>p){cerr<<"["<<p.ff<<","<<p.ss<<"]";}
void _print(int x){cerr<<x;}
void _print(ll x){cerr<<x;}
void _print(string& x){cerr<<x;}
void _print(char x){cerr<<x;}
template<class T>void _print(vector<T>&v){cerr<<"[ ";for(T i:v){_print(i);cerr<<" ";}cerr<<"]\n";}
template<class T>void _print(set<T>&pt){cerr<<"[ ";for(T i:pt){_print(i);cerr<<" ";}cerr<<"]\n";}
template<class T>void _print(multiset<T>&pt){cerr<<"[ ";for(T i:pt){_print(i);cerr<<" ";}cerr<<"]\n";}
//*********************************************************************
 
//useful functions....
//*********************************************************************
ll gcd(ll a,ll b){if(b==0)return a;else return gcd(b,a%b);}
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}
ll ceil(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}
ll binpow(ll a,ll b){ll res = 1;while(b!=0){if(b%2){res*=a;}a*=a;b/=2;}return res;}
ll binmod(ll a,ll b,ll m){a %= m;ll res = 1;while (b > 0) {if (b & 1)res = res * a % m;a = a * a % m;b >>= 1;}return res;}
//if m is prime
ll modinv(ll a,ll m){return binmod(a,m-2,m);}
//*********************************************************************
 
const int N = 2e6+110;
const int maxn = 2e5+10;
const ll mod = 1e9+7;
 
 
void solve(int T){
    int n,q;
    cin>>n>>q;
    vector<ll>v(n);
    for(ll& i:v)cin>>i;
    vector<ll>pref(n+1,0);
    for(int i=0;i<n;i++){
        pref[i+1] = pref[i] + v[i];
    }
    while(q--){
        int a,b;
        cin>>a>>b;
        cout<<pref[b] - pref[a-1]<<endl;
    }
}
 
 
int main(){
    srand(time(NULL));
    bahut_tez;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("Error.txt","w",stderr);
    #endif
    int t=1;
    auto start = high_resolution_clock::now();
    //cin>>t;
    for(int i=1;i<=t;i++){
        solve(i);
    }
    auto end=  high_resolution_clock::now();
    double duration = duration_cast<nanoseconds>(end - start).count();
    duration *= 1e-9;
 
    #ifndef ONLINE_JUDGE
        cerr<<"Time - "<<fixed<<duration<<setprecision(9) <<" s"<<endl;
    #endif
    return 0;
}