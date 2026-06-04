// https://www.hackerrank.com/contests/goc-cdc-series-3/challenges/another-number-problem/problem?isFullScreen=true
//
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
#define endl '\n'

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n; cin >> n;
    ll mod = 1e9+7;
    vector<ll> dp(n+1, 0);
    dp[3] = dp[5] = dp[10] = 1;
    for(ll i = 1; i <= n; i++) {
        if(i-3 >= 0) dp[i] = (dp[i] + dp[i-3]) % mod;
        if(i-5 >= 0) dp[i] = (dp[i] + dp[i-5]) % mod;
        if(i-10 >= 0) dp[i] = (dp[i] + dp[i-10]) % mod;
    }
    cout << dp[n] << endl;
    
    return 0;
}
