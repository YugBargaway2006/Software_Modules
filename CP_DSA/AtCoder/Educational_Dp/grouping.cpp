// 23 : 54
#include <bits/stdc++.h>
using namespace std;

#define  ll long long
#define endl '\n'

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    vector<vector<ll>> a(n, vector<ll>(n));

    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    ll M = 1 << n;

    vector<ll> score(M, 0);

    for(ll mask = 0; mask < M; mask++) {
        for(ll i = 0; i < n; i++) {
            if(!(mask & (1 << i))) continue;

            for(ll j = i + 1; j < n; j++) {
                if(mask & (1 << j)) {
                    score[mask] += a[i][j];
                }
            }
        }
    }

    vector<ll> dp(M, LLONG_MIN);
    dp[0] = 0;

    for(ll mask = 1; mask < M; mask++) {

        for(ll sub = mask; sub; sub = (sub - 1) & mask) {

            dp[mask] = max(
                dp[mask],
                dp[mask ^ sub] + score[sub]
            );
        }
    }

    cout << dp[M - 1] << endl;
}