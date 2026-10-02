#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll MOD = 1000000007;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, 0));

    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {

        ll total = 0;
        for (int j = 0; j <= k; j++) {
            total = (total + dp[i - 1][j]) % MOD;
        }

        dp[i][0] = (21 * total) % MOD;

        for (int j = 1; j <= k; j++) {
            dp[i][j] = (5 * dp[i - 1][j - 1]) % MOD;
        }
    }

    ll ans = 0;
    for (int j = 0; j <= k; j++) {
        ans = (ans + dp[n][j]) % MOD;
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) solve();
}