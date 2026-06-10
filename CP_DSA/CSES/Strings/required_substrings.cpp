// 14 : 33   :::::::: REVISE HARSHLY
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ll mod = 1e9+7;

ll modexp(ll b, ll p) {
    ll res = 1;
    while(p) {
        if(p & 1) res = res * b % mod;
        b = b*b % mod;
        p >>= 1;
    }   
    return res;
}

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n; string s;
    cin >> n >> s;
    ll m = s.size();

    // KMP Algorithm
    vector<ll> pi(m);
    for(ll i = 1; i < m; i++) {
        ll j = pi[i-1];
        while(j > 0 && s[i] != s[j]) {
            j = pi[j-1];
        }
        if(s[i] == s[j]) j++;
        pi[i] = j;
    }

    // DP
    vector<vector<ll>> dp(n+1, vector<ll>(m, 0));
    dp[0][0] = 1;
    for(ll i = 0; i < n; i++) {
        for(ll matched = 0; matched < m; matched++) {
            if(dp[i][matched] == 0) continue;

            for(char c = 'A'; c <= 'Z'; c++) {
                ll cur = matched;
                while(cur > 0 && s[cur] != c) {
                    cur = pi[cur-1];
                }

                if(s[cur] == c) cur++;
                if(cur == m) continue;

                dp[i+1][cur] = (dp[i+1][cur] + dp[i][matched]) % mod;
            }
        }
    }

    ll bad = 0;
    for(ll j = 0; j < m; j++) {
        bad = (bad + dp[n][j]) % mod;
    }

    ll total = modexp(26, n);
    cout << (total - bad + mod) % mod << endl;
}