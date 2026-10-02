#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll dp[1 << 13][2][2];
int a[13][13];
int n;

ll dfs(int mask, int has1, int has3) {
    if (mask == (1 << n) - 1)
        return (!has1 || has3);

    ll &ans = dp[mask][has1][has3];
    if (ans != -1) return ans;

    ans = 0;

    int child = __builtin_popcount(mask);

    for (int gift = 0; gift < n; gift++) {
        if (mask & (1 << gift)) continue;

        ans += dfs(mask | (1 << gift),
                   has1 || (a[child][gift] == 1),
                   has3 || (a[child][gift] == 3));
    }

    return ans;
}

void solve() {
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    memset(dp, -1, sizeof(dp));

    cout << dfs(0, 0, 0) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
        solve();
}