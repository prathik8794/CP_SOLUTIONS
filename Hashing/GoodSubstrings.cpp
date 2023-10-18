//https://codeforces.com/problemset/problem/271/D

#include <bits/stdc++.h>
using namespace std;

const int mod1 = 1e9 + 7;
const int mod2 = 1e9 + 9;
using lli = long long;

vector<vector<lli>> dp;
vector<vector<lli>> inv;

lli power(lli a, lli n, lli mod) {
    lli result = 1;
    while (n) {
        if (n & 1) result = (result * a) % mod;
        n >>= 1;
        a = (a * a) % mod;
    }
    return result;
}

void init(string s) {
    lli p = 31, q = 61;
    lli p_power = 1, q_power = 1;
    int n = s.size();
    dp.assign(n, vector<lli>(2));
    inv.assign(n, vector<lli>(2));

    inv[0][0] = 1;
    inv[0][1] = 1;
    dp[0][0] = (s[0] - 'a' + 1);
    dp[0][1] = (s[0] - 'a' + 1);

    for (int i = 1; i < n; i++) {
        char ch = s[i];
        p_power = (p_power * p) % mod1;
        q_power = (q_power * q) % mod2;
        inv[i][0] = power(p_power, mod1 - 2, mod1);
        inv[i][1] = power(q_power, mod2 - 2, mod2);

        dp[i][0] = (dp[i - 1][0] + (ch - 'a' + 1) * p_power) % mod1;
        dp[i][1] = (dp[i - 1][1] + (ch - 'a' + 1) * q_power) % mod2;
    }
}

pair<lli, lli> substringHash(int L, int R) {
    lli result = dp[R][0];
    if (L > 0) result = (result - dp[L - 1][0] + mod1) % mod1;
    result = (result * inv[L][0]) % mod1;

    lli result2 = dp[R][1];
    if (L > 0) result2 = (result2 - dp[L - 1][1] + mod2) % mod2;
    result2 = (result2 * inv[L][1]) % mod2;
    return {result, result2};
}

int main() {
    string s;
    cin >> s;
    int bad[26] = {0};
    char x;
    for (int i = 0; i < 26; i++) {
        cin >> x;
        bad[i] = 1 - (x - '0');
    }
    int k;
    cin >> k;
    init(s);
    set<pair<lli, lli>> unq;
    int n = (int)s.length();
    for (int i = 0; i < n; i++) {
        int ct = 0;
        for (int j = i; j < n; j++) {
            if (bad[s[j] - 'a']) ct++;
            if (ct > k) break;
            unq.insert(substringHash(i, j));
        }
    }
    cout << (int)unq.size() << endl;
    return 0;
}
