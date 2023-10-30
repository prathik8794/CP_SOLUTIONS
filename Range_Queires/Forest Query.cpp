/**
 * @file code.cpp
 * @author udtha kouwa
 * @created: 13/3/2022
 */
 
//see this header sometimes automatically includes some non sense library 
#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define pii pair<int,int>  
#define pll pair<ll,ll>
#define pb push_back
#define bahut_tez  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define ss second
#define ff first 
#define vi vector<int>
#define endl "\n"
#define NO cout<<"No\n"
#define YES cout<<"Yes\n"
#define INF LLONG_MAX
 
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
 
 
const int N = 1e6+10;
const int mod = 1e9+7;
 
 
 
 
 
 
void solve(int T){
    int n,q;
    cin>>n>>q;
    vector<vector<int>>v(n+1,vector<int>(n+1));
    ll sum = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            char c;
            cin>>c;
            v[i][j]=(c=='*');
        }
    }
    //debug(v)
    vector<vector<int>>pref(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            pref[i][j] = pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1]+v[i][j];
        }
    }
   // debug(pref)
    while(q--){
        int a,b,A,B;
        cin>>a>>b>>A>>B;
        int sum = pref[A][B] - pref[A][b-1] - pref[a-1][B] + pref[a-1][b-1];
        cout<<sum<<endl;
    }
 
}
 
 
int32_t main(){
    srand(time(NULL));
    bahut_tez;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
    #endif
    int t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        solve(i);
    }
    
    return 0;
