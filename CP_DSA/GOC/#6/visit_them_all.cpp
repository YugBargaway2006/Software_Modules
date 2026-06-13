// https://www.hackerrank.com/contests/goc-cdc-series-6/challenges/visit-them-all/problem?isFullScreen=true

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
#define endl '\n'

ll mxn = 18; 
ll INT_MAX = 1e15;
vector<vector<ll>> bitmask(1 << mxn, vector<ll>(mxn, INT_MAX));

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n, m; cin >> n >> m;
    vector<vector<ll>> adj(n);
    vector<vector<ll>> dp(n, vector<ll>(n, INT_MAX));
    for(ll i = 0; i < m; i++) {
        ll x, y, z; cin >> x >> y >> z;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
        dp[x][y] = dp[y][x] = z;
    }
    
    for(ll i = 0; i < n; i++) {
        dp[i][i] = 0;
    }
    for(ll k = 0; k < n; k++) {
        for(ll i = 0; i < n; i++) {
            for(ll j = 0; j < n; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    
    bitmask[1][0] = 0;
    for(ll i = 1; i < (1 << n); i++) {
        for(ll j = 0; j < n; j++) {
            if((i & (1 << j)) != 0) {
                continue;
            }
            ll newmask = i | (1 << j);
            for(ll k = 0; k < n; k++) {
                if((i & (1 << k)) == 0) {
                    continue;
                }   
                bitmask[newmask][j] = min(bitmask[newmask][j], bitmask[i][k] + dp[k][j]);
            }
        }
    }
    
    cout << bitmask[(1<<n)-1][n-1] << endl;
    
    return 0;
}
