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
struct segtree{
    int size;
 
    vector<long long>sums;
 
    void init(int n){
 
        size = 1;
        //making array size power of 2;
        while(size < n)size*=2;
        
        sums.assign(2*size,LLONG_MAX);
    }
    void build(vector<int>&a,int x,int lx,int rx){
        //building segtree in O(N)
        if(rx-lx==1){
            if(lx<(int)(a.size())){
                sums[x] = a[lx];
            }
            return;
        }
        int m = (lx+rx)/2;
        build(a,2*x+1,lx,m);
        build(a,2*x+2,m,rx);
        sums[x] = min(sums[2*x+1],sums[2*x+2]);
    }
    void build(vector<int>&a){
        build(a,0,0,size);
    }
    void set(int i,int v,int x,int lx,int rx){
        //set the index i with value v
        if(rx-lx==1){
            sums[x] = v;
            return;
        }
        int m = (lx+rx)/2;
        if(i<m){
            set(i,v,2*x+1,lx,m);
        }else{
            set(i,v,2*x+2,m,rx);
        }
        sums[x] = min(sums[2*x+1],sums[2*x+2]);
    }
    void set(int i,int v){
        set(i,v,0,0,size);
    }
    long long sum(int l,int r,int x,int lx,int rx){
        //getting sum between l to r
        //1. interval doesnt intersect
        if(l>=rx || lx>=r)return LLONG_MAX;
        //2 . intervals intersect completely inside
        if(lx>=l && rx<=r)return sums[x];
        //3 . interval intersect partially.
        int m = (lx+rx)/2;
        long long s1 = sum(l,r,2*x+1,lx,m);
        long long s2 = sum(l,r,2*x+2,m,rx);
        return min(s1,s2);
    }
    long long sum(int l,int r){
        return sum(l,r,0,0,size);
    }
};
 
void solve(int T){
    int n,q;
    cin>>n>>q;
    vector<int>v(n);
    for(int& i:v)cin>>i;
    segtree st;
    st.init(n);
    st.build(v);
    while(q--){
        int a,b;
        cin>>a>>b;
        a--;
        cout<<st.sum(a,b)<<endl;
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
