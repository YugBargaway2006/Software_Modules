// 00 : 20 :::: Remember the Greedy Logic
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ll n;
vector<vector<ll>> arr;

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    arr.assign(n, vector<ll>(3, 0));
    for(ll i = 0; i < n; i++) {
        cin >> arr[i][1] >> arr[i][0] >> arr[i][2];
    }
    sort(arr.begin(), arr.end());

    map<ll, ll> dp;
    dp[0] = 0;
    for(auto& x : arr) {
        ll e = x[0], s = x[1], r = x[2];

        auto it = dp.lower_bound(s);
        ll bb = 0;
        if(it != dp.begin()) {
            --it;
            bb = it->second;
        }
        
        ll candi = bb + r;
        ll bn = max(dp.rbegin()->second, candi);
        dp[e] = max(dp[e], bn);
    }

    cout << dp.rbegin()->second << endl;
    
}