// ::::::::::::::::::: REVISE RIGOUROUSLY WITH VISUALIZATION
#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll dp[20][11][2][2];
string s;

ll dfs(int pos, int prev, int tight, int started) {
    if (pos == s.size()) return 1;

    if (dp[pos][prev][tight][started] != -1)
        return dp[pos][prev][tight][started];

    ll ans = 0;
    int lim = tight ? s[pos] - '0' : 9;

    for (int d = 0; d <= lim; d++) {
        int ntight = (tight && d == lim);

        if (!started && d == 0) {
            ans += dfs(pos + 1, 10, ntight, 0);
        }
        else {
            if (started && d == prev) continue;
            ans += dfs(pos + 1, d, ntight, 1);
        }
    }

    return dp[pos][prev][tight][started] = ans;
}

ll solve(ll x) {
    if (x < 0) return 0;
    s = to_string(x);
    memset(dp, -1, sizeof(dp));
    return dfs(0, 10, 1, 0);
}

int main() {
    ll a, b;
    cin >> a >> b;
    cout << solve(b) - solve(a - 1) << '\n';
}