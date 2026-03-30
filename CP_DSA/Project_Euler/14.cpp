#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define int long long

vector<int> dp(1000001, -1);

int chain(int n) {
    if(n == 1) return 1;
    if(n > 1e6) {
        if(n%2 == 0) return 1 + chain(n/2);
        else return 1 + chain(3*n + 1);
    }
    if(dp[n] != -1) return dp[n];
    // cout << "done" << endl;

    if(n % 2 == 0) {
        dp[n] = 1 + chain(n/2);
    } else {
        dp[n] = 1 + chain(3*n + 1);
    }

    cout << dp[n] << endl;
    return dp[n];
}

signed main(void) {
    dp[1] = 1;
    for(int i = 1; i <= 1e6; i++) {
        if(dp[i] == -1) chain(i);
    }

    for(auto i : dp) cout << i << " ";
    cout << endl;

    int ans_idx = 0;
    int ma = 0;
    for(int i = 1; i <= 1e6; i++) {
        if(dp[i] > ma) {
            ma = dp[i];
            ans_idx = i;
        }
    }

    cout << ans_idx << endl;
}