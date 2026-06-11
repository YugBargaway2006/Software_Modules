// 23 : 54
#include <bits/stdc++.h>
using namespace std;

#define  ll long long
#define endl '\n'

struct pt {
    ll f, s;
};

ll n; vector<ll> arr;
vector<vector<pt>> dp;
vector<vector<bool>> vis;
// vector<ll> pre;

pt score(ll l, ll r) {
    if(l == r) {
        dp[l][l] = {arr[l], 0};
        return {arr[l], 0};
    }
    if(vis[l][r]) return dp[l][r];
    vis[l][r] = true;

    pt c1 = score(l+1, r);
    pt c2 = score(l, r-1);
    if(arr[l] + c1.s - c1.f >= arr[r] + c2.s - c2.f) return dp[l][r] = {arr[l]+c1.s, c1.f};
    else return dp[l][r] = {arr[r]+c2.s, c2.f};
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    arr.resize(n);
    dp.assign(n, vector<pt>(n, {0,0}));
    vis.assign(n, vector<bool>(n, false));
    // pre.assign(n, 0);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
        // pre[i] = arr[i];
        // if(i > 0) pre[i] += pre[i-1]; 
    }

    pt ans = score(0, n-1);
    // for(ll i = 0; i < n; i++) {
    //     for(ll j = 0; j < n; j++) {
    //         cout << dp[i][j].f << " " << dp[i][j].s << " . ";
    //     }
    //     cout << endl;
    // }

    cout << ans.f - ans.s << endl;
}