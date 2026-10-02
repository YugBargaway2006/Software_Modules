#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int NEG = -1e9;

void solve() {
    int K;
    cin >> K;

    vector<int> cost(10);
    for (int i = 1; i <= 9; i++)
        cin >> cost[i];

    vector<int> dp(K + 1, NEG);
    dp[0] = 0;

    for (int i = 1; i <= K; i++) {
        for (int d = 1; d <= 9; d++) {
            if (i >= cost[d] && dp[i - cost[d]] != NEG)
                dp[i] = max(dp[i], dp[i - cost[d]] + 1);
        }
    }

    if (dp[K] < 0) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    string ans;
    int cur = K;
    while (cur > 0) {
        for (int d = 9; d >= 1; d--) {
            if (cur >= cost[d] &&
                dp[cur - cost[d]] == dp[cur] - 1) {
                ans.push_back(char('0' + d));
                cur -= cost[d];
                break;
            }
        }
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