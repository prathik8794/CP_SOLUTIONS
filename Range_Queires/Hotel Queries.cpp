/**
 * @file code.cpp
 * @created: 13/3/2022
 */
 
/**
/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include
*/
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
#define ah_yeah  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define ss second
#define ff first
#define vi vector<int>
#define vb vector<bool>
#define vll vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define FOR(i,j,n) for(int i=j;i<n;i++)
 
//  input
template <typename T> ostream& operator<<(ostream& s, const vector<T>& self) { for (auto &e : self) { s << e << ' '; } return s; }
template <typename T> istream& operator>>(istream& s, vector<T>& self) { for (size_t i = 0; i < self.size(); ++i) { s >> self[i]; } return s; }
 
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << "\n"; _print(x); cerr << endl;
#else
#define debug(x)
#endif
 
// debugging
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
 
// useful functions....
//*********************************************************************
ll gcd(ll a,ll b){if(b==0) return a; else return gcd(b,a%b);}
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}
ll ceil(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}
ll binpow(ll a,ll b){ll res = 1;while(b!=0){if(b%2){res*=a;}a*=a;b/=2;}return res;}
ll binmod(ll a,ll b,ll m){a %= m;ll res = 1;while (b > 0) {if (b & 1)res = res * a % m;a = a * a % m;b >>= 1;}return res;}
// if m is prime
ll modinv(ll a,ll m){return binmod(a,m-2,m);}
//*********************************************************************
 
const ll mod = 1e9+7;
struct segtree{
    int size;
 
    vector<long long>sums;
    void init(int n){
 
        size = 1;
        //making array size power of 2;
        while(size < n)size*=2;
        sums.assign(2*size,0);
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
        sums[x] = max(sums[2*x+1],sums[2*x+2]);
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
        sums[x] = max(sums[2*x+1],sums[2*x+2]);
    }
    void set(int i,int v){
        set(i,v,0,0,size);
    }
    long long query(int x,int lx,int rx,int need){
        if(sums[x]<need){
            return -1;
        }
        if(rx-lx==1){
            sums[x]-=need;
            return lx;
        }
        int m = (lx+rx)/2;
        ll res ; 
        if(sums[2*x+1]>=need){
            res =  query(2*x+1,lx,m,need);
        }else{
            res =  query(2*x+2,m,rx,need);
        }
        sums[x] = max(sums[2*x+1],sums[2*x+2]);
        return res;
    }
    long long query(int need){
        return query(0,0,size,need);
    }
};
int n,m;
vi v;
segtree st;
void solve (int _T){
    cin >> n >> m;
    v.resize(n);
    for(int i=0;i<n;i++)cin>>v[i];
    st.init(n);
    st.build(v);
    for(int i=0;i<m;i++){
        int need;
        cin >> need;
        ll in = st.query(need);
        if(in==-1)cout<<0<<" ";
        else cout << in+1 << " ";
        
    }
}
 
signed main(){
    ah_yeah;
    srand(time(__null));
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
    #endif
    int t = 1;
    //cin >> t;
    for(int i=1; i<=t; i++){
        // cout << "Case #" << i << ": ";
        solve(i);
    }
    return 0;
} 