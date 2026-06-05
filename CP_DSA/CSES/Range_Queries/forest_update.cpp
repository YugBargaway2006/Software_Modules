// 11 : 51
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ll n, q, m;
vector<vector<char>> arr;
vector<vector<ll>> prefix;

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    m = n;
    arr.assign(n, vector<char>(m));
    prefix.assign(n, vector<ll>(m, 0));

    for(ll i = 0; i < n; i++) {
        for(ll j= 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    for(ll i = 0; i < n; i++) {
        for(ll j= 0; j < m; j++) {
            prefix[i][j] += (arr[i][j] == '*') ? 1 : 0;
            if(j > 0) prefix[i][j] += prefix[i][j-1];
            if(i > 0)prefix[i][j] += prefix[i-1][j];
            if(i > 0 && j > 0) prefix[i][j] -= prefix[i-1][j-1];
        }
    }

    while(q--) {
        ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        x1--; y1--; x2--; y2--;
        ll ans = prefix[x2][y2];
        // cout << ans << endl;
        if(x1 > 0) ans -= prefix[x1-1][y2];  
        // cout << ans << endl;
        if(y1 > 0) ans -= prefix[x2][y1-1];  
        // cout << ans << endl;
        if(x1 > 0 && y1 > 0) ans += prefix[x1-1][y1-1];  

        cout << ans << endl;
    }
}