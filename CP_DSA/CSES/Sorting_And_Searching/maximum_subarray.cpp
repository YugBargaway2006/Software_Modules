// *** 17 : 16
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

signed main(void) {
    int n; cin >> n;
    int sum = 0;
    int mx = 0;
    int mv = -1e15;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        mv = max(mv, x);
        sum = max(0LL, sum+x);
        mx = max(sum, mx);
    }
    int ans = (mx == 0) ? mv : mx;
    cout << ans << endl;
}

// 17 : 22