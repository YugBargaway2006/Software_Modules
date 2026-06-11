// 12 : 08 :::: Remember how the logic flowed
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'



signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, x; cin >> n >> x;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ll mx = 1 << n;
    vector<pair<ll, ll>> dp(mx+1, {1e18, 1e18});
    dp[0] = {1, 0};
    for(ll i = 1; i < mx; i++) {
        for(ll j = 0; j < n; j++) {
            if(i & (1LL << j) == 0) continue;
            auto prev = dp[i ^ (1 << j)];
            pair<ll, ll> candi;
            if(arr[j] + prev.second <= x) {
                candi = {prev.first, prev.second + arr[j]};
            } 
            else {
                candi = {prev.first + 1, arr[j]};
            }
            dp[i] = min(dp[i], candi);
        }
    }
    cout << dp[mx-1].first << endl;
}