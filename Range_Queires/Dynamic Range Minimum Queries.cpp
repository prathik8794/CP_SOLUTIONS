#include<bits/stdc++.h>
using namespace std;
 
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
int main(){
    int n,m;
    cin>>n>>m;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    segtree st;
    st.init(n);
    st.build(v);
    cout<<endl;
    while(m--){
        int op;
        cin>>op;
        if(op==1){
            int i,v;
            cin>>i>>v;
            i--;
            st.set(i,v);
        }else{
            int l,r;
            cin>>l>>r;
            l--;
            cout<<st.sum(l,r)<<"\n";
        }
    }
}
