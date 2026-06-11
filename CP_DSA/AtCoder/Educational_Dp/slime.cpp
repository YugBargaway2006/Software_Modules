#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<ll> a(n);
    vector<ll> pre(n + 1, 0);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        pre[i + 1] = pre[i] + a[i];
    }

    auto sum = [&](int l, int r) {
        return pre[r + 1] - pre[l];
    };

    vector<vector<ll>> dp(n, vector<ll>(n, 0));

    for(int len = 2; len <= n; len++) {
        for(int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;

            dp[i][j] = LLONG_MAX;

            for(int k = i; k < j; k++) {
                dp[i][j] = min(
                    dp[i][j],
                    dp[i][k] + dp[k + 1][j] + sum(i, j)
                );
            }
        }
    }

    cout << dp[0][n - 1] << endl;
}