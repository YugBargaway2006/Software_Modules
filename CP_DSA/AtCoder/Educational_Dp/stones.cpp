// 23 : 54
#include <bits/stdc++.h>
using namespace std;

#define  ll long long
#define endl '\n'

vector<bool> dp;
vector<ll> arr;
ll n, k;
vector<bool> vis;

bool solve(ll k) {
    if(k < 0) return true;
    if(vis[k]) return dp[k];
    vis[k] = true;

    for(ll i = 0; i < n; i++) {
        bool res = solve(k - arr[i]);
        if(!res) {
            dp[k] = true;
            return true;
        }
    }
    return false;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    dp.assign(k+1, false);
    arr.assign(n, 0);
    vis.assign(k+1, false);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    dp[0] = false;
    if(solve(k)) cout << "First" << endl;
    else cout << "Second" << endl;

    // for(ll i = 0; i <= k; i++) {
    //     for(ll j = 0; j <= n; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}