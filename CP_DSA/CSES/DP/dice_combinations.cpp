#include <bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define int long long 
#define INT_MAX LLONG_MAX
#define vi vector<int>
#define pi pair<int, int>
#define f(i,k,n) for(int i = k; i < n; i++)
#define mi map<int>
#define si set<int>
#define debug(i) cout << i << endl
 
 
int ways(int n, int mod, vi& dp) {
    if(n < 0) {
        return 0;
    }
    if(n == 0) return 1;
 
    if(dp[n]!= -1) return dp[n]%mod;
 
    int w1 = ways(n-1, mod, dp) % mod;
    int w2 = ways(n-2, mod, dp) % mod;
    int w3 = ways(n-3, mod, dp) % mod;
    int w4 = ways(n-4, mod, dp) % mod;
    int w5 = ways(n-5, mod, dp) % mod;
    int w6 = ways(n-6, mod, dp) % mod;
 
    dp[n] = w1 + w2 + w3+ w4 + w5 + w6;
    return w1 + w2 + w3+ w4 + w5 + w6;
}
 
 
void solve() {
    int n; cin >> n;
    int mod = 1e9 + 7;
    vi dp(n+1, -1);
    cout << ways(n, mod, dp)%mod;
}
 
 
signed main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    // int t; cin >> t;
    int t = 1;
    while(t--) {
        // cout << "solve called" << endl;
        solve();
    }
}
