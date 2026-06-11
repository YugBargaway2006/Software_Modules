// 23 : 54
#include <bits/stdc++.h>
using namespace std;

#define  ll long long
#define endl '\n'

ll n, k;
vector<vector<ll>> dp;
ll mod = 1e9+7;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    dp.assign(n, vector<ll>(k+1, 0));

    vector<ll> arr(n);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<ll> pre(k+1);
    for(ll i = 0; i <= k; i++) {
        if(i <= arr[0]) dp[0][i] = 1;
        // if(i == arr[0]) dp[0][i] = 1;
        pre[i] = dp[0][i];
        if(i > 0) pre[i] += pre[i-1];
    }
    // vector<ll> newpre(k+1, 0);
    for(ll i = 1; i < n; i++) {
        // cout << "[PRE] ";
        // for(auto x : pre) cout << x << " "; cout << endl;
        for(ll j = 0; j <= k; j++) {
            dp[i][j] = pre[j];
            if(j - arr[i] > 0) dp[i][j] -= pre[j-arr[i]-1];
            dp[i][j] %= mod;
            dp[i][j] += mod;
            dp[i][j] %= mod;
            // newpre[j] = dp[i][j];
            // if(j > 0) newpre[j] += dp[i][j-1];
        }
        for(ll j = 0; j <= k; j++) {
            pre[j] = dp[i][j];
            if(j > 0) pre[j] += pre[j-1];
            pre[j] %= mod;
        }
        // pre = newpre;
    }

    // for(ll i = 0; i < n; i++) {
    //     for(ll j = 0; j <= k; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << dp[n-1][k] % mod << endl;
}