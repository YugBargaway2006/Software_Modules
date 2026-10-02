// 23 : 55
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, a, b; cin >> n >> a >> b;
    vector<vector<double>> dp(n+1, vector<double>(6*n+1, 0));
    dp[0][0] = 1;
    for(ll i = 1; i <= n; i++) {
        for(ll j = 1; j <= 6*i; j++) {
            for(ll k = 1; k <= 6; k++) {
                dp[i][j] += (dp[i-1][j-k])/6;
            }
        }
    }

    double ans = 0;
    for(ll i = a; i <= b; i++) {
        ans += dp[n][i];
    }
    printf("%.6f\n", ans);
}