// *** 17 : 04
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<pair<int, int>> t(n);
    for(int i = 0; i < n; i++) cin >> t[i].second >> t[i].first;
    sort(t.begin(), t.end());

    int count = 0;
    int ct = 0;
    for(int i = 0; i < n; i++) {
        auto [b, a] = t[i];
        if(a >= ct) {
            count++;
            ct = b;
        }
    }
    cout << count << endl;
}

// 17 : 08