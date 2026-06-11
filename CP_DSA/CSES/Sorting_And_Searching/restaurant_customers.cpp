// *** 16 : 58
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int n;

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    // Leaving : 0, Coming : 1
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    int count = 0;
    while(n--) {
        int a, b; cin >> a >> b;
        q.push({a, 1});
        q.push({b, 0});
    }

    int mx = 0;
    while(!q.empty()) {
        auto [t, v] = q.top(); q.pop();
        (v == 1) ? ++count : --count;
        mx = max(mx, count);
    }
    cout << mx << endl;
}

// 17 : 03