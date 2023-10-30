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
 
const ll mod = 998244353;
 
class SegTree{
    public:
    const int N = 2e5+10;
    int n;
    ll int *seg_tree, *lazy;
    SegTree(){
        seg_tree = new ll int[4*N];
        lazy = new ll int[4*N];
    }
 
    void init(vector<ll int> &arr, int n){
        this->n = n;
        build_seg_tree(arr, n);
    }
 
    void propagate(int v, int l, int r){
        if (lazy[v]==0)
            return;
        if (lazy[v]!=0){
            seg_tree[v]+=(r-l+1)*lazy[v];
            if (l!=r){
                lazy[v<<1]+=lazy[v];
                lazy[v<<1|1]+=lazy[v];
            }
        }
        lazy[v]=0;
    }
 
    void build(int v, int l, int r, vector<ll int> &arr){
        lazy[v]=0;
        if (l==r){
            seg_tree[v]=arr[l];
            return;
        }
 
        int m=(l+r)>>1;
        build(v<<1,l,m, arr);
        build(v<<1|1,m+1,r, arr);
        seg_tree[v]=seg_tree[v<<1]+seg_tree[v<<1|1];
    }
 
    void update(int v, int l, int r, int ss, int se, ll int val){
        propagate(v,l,r);
 
        if (ss>se)
        return;
 
        if (l==ss && r==se){
            seg_tree[v]+=val*(r-l+1);
            if (l!=r){
                lazy[v<<1]+=val;
                lazy[v<<1|1]+=val;
            }
            return;
        }
 
        int m=(l+r)>>1;
        update(v<<1,l,m,ss,min(se,m),val);
        update(v<<1|1,m+1,r,max(m+1,ss),se,val);
        seg_tree[v]=seg_tree[v<<1]+seg_tree[v<<1|1];
    }
 
    ll int query(int v, int l, int r, int ss, int se){
        propagate(v,l,r);
        if (ss>se)
            return 0;
        if (l==ss && r == se)
            return seg_tree[v];
        int m=(l+r)>>1;
        return query(v<<1,l,m,ss,min(se,m)) + query(v<<1|1,m+1,r,max(m+1,ss),se);
    }
 
    void build_seg_tree(vector<ll int> &arr, ll int n){
        build(1, 0, n-1, arr);
    }
 
    void updateRange(int l, int r, ll int val){
        update(1,0,n-1,l,r,val);
    }
 
    ll int getSum(int l, int r){
        return query(1,0,n-1,l,r);
    }
};
SegTree st;
void solve (int _T){
    int n,q;
    cin >> n >> q;
    vll v(n);
    cin >> v;
    st.init(v,n);
    while(q--){
        int op;
        cin >> op;
        if(op == 1){
            int l,r,val;
            cin >> l >> r >> val;
            l--;r--;
            st.updateRange(l,r,val);
        }else{
            int k;
            cin >> k;
            k--;
            cout << st.getSum(k,k) << endl;
        }
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
        //cout << "Case #" << i << ": ";
        solve(i);
    }
    return 0;
}   