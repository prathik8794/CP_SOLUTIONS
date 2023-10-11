#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
using cd = complex<double>;
const double PI = acos(-1);
 
void fft(vector<cd> & a, bool invert) {
    int n = (int)a.size();
    if (n == 1)
        return;
 
    vector<cd> a0(n / 2), a1(n / 2);
    for (int i = 0; 2 * i < n; i++) {
        a0[i] = a[2*i];
        a1[i] = a[2*i+1];
    }
    fft(a0, invert);
    fft(a1, invert);
 
    double ang = 2 * PI / n * (invert ? -1 : 1);
    cd w(1), wn(cos(ang), sin(ang));
    for (int i = 0; 2 * i < n; i++) {
        a[i] = a0[i] + w * a1[i];
        a[i + n/2] = a0[i] - w * a1[i];
        if (invert) {
            a[i] /= 2;
            a[i + n/2] /= 2;
        }
        w *= wn;
    }
}
 
vector<long long> multiply(vector<int> const& a, vector<int> const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size())
        n <<= 1;
    fa.resize(n);
    fb.resize(n);
 
    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);
 
    vector<long long> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}
 
void solve ( int _T ){
    int n;
    cin >> n;
    vector<int>a(n+1),b(n+1);
    for(int i=0;i<n+1;i++)cin >> a[i];
    for(int i=0;i<n+1;i++)cin >> b[i];
    vector<long long>res = multiply(a , b);
    for(int i=0;i<2*n+1;i++){
        cout << res[i] << " ";
    }
    cout<<endl;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    for ( int  i = 1 ; i <= t ; i++ ){
        solve(i);
    }
}