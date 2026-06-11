// https://www.hackerrank.com/contests/goc-cdc-series-3/challenges/jumping-fever/problem?isFullScreen=true
//  "::::::: DP
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
    vector<ll> arr(n), crr(n);
    for(ll i = 0; i < n; i++) {
        cin >> crr[i];
    }
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    vector<ll> dp(n, 1e15);
    dp[0] = crr[0];
    for(ll i = 0; i < n;i++) {
        for(ll j = 1; j <= arr[i]; j++) {
            if(i+j < n) {
                dp[i+j] = min(dp[i+j], dp[i] + crr[i+j]);
                // cout << i+j << " -> " << dp[i+j] << endl;
            }
        }
    }
    cout << dp[n-1] << endl;
    
    return 0;
}
