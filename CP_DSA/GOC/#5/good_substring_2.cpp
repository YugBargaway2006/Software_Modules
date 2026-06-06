// https://www.hackerrank.com/contests/goc-cdc-series-5/challenges/good-substrings-2-1/problem?isFullScreen=true
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
#define endl '\n'

void solve() {
    ll n; cin >> n;
    string s; cin >> s;
    vector<ll> dp;
    ll ct = 1;
    for(ll i = 1; i < n; i++) {
        if(s[i-1] != s[i]) {
            dp.push_back(ct);
            ct = 1;
        } else {
            ct++;
        }
    }
    dp.push_back(ct);
    
    // for(auto x : dp) cout << x << " "; cout << endl;
    ll ans = 0;
    for(ll i = 1; i < dp.size(); i++) {
        ans += min(dp[i-1], dp[i]);
    }
    cout << ans <<endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll t; cin >> t;
    while(t--) {
        solve();
    }
    
    return 0;
}
