// 12 : 47     :::::::::: Understand the DP formulation
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ll n, m;
vector<ll> arr;
vector<vector<ll>> dp;
ll mod =  1e9+7;

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    arr.assign(n, 0);
    dp.assign(n, vector<ll>(m+1, 0));
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if(arr[0] == 0) {
        for(ll i = 1; i <= m; i++) {
            dp[0][i] = 1;
        }
    } else {
        dp[0][arr[0]] = 1;
    }

    for(ll i = 1; i < n; i++) {
        if(arr[i] != 0) {
            dp[i][arr[i]] = dp[i-1][arr[i]] % mod;
            if(arr[i] != 1) dp[i][arr[i]] += dp[i-1][arr[i]-1] % mod;
            if(arr[i] != m) dp[i][arr[i]] += dp[i-1][arr[i]+1] % mod;
        } 
        else {
            for(ll j = 1; j <= m; j++) {
                dp[i][j] = dp[i-1][j] % mod;
                if(j != 1) dp[i][j] += dp[i-1][j-1] % mod;
                if(j != m) dp[i][j] += dp[i-1][j+1] % mod;                       
            }
        }
    }
    ll sum = 0;
    for(ll i = 1; i <= m; i++) {
        sum += dp[n-1][i] % mod;
    }
    cout << sum % mod << endl;
} 