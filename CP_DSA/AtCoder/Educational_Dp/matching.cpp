// 14 : 07
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ll n;
ll mod = 1e9+7;
vector<vector<ll>> arr;
vector<ll> dp;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    arr.assign(n, vector<ll>(n, 0));
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    dp.assign(1 << n, 0);
    dp[0] = 1;
    for(ll i = 0; i < (1<<n)-1; i++) {
        ll k = __builtin_popcount(i);
        for(ll j = 0; j< n; j++) {
            if(arr[k][j] == 1 && ((i & (1 << j)) == 0)) {
                ll nm = i | (1 << j);
                dp[nm] = (dp[nm] + dp[i]) % mod;
            }
        }
    }
    cout << dp[(1 << n)-1] << endl;
}