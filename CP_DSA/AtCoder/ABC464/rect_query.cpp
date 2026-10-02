#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define endl '\n'


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, m, q; cin >> n >> m >> q;
    vector<vector<ll>> arr(n+1, vector<ll>(m+1, 0));
    vector<char> trans(q+1);
    trans[0] = 'A';
    for(ll i = 1; i <= q; i++) {
        ll x, y; cin >> x >> y;
        arr[x][y] = i;
        char d; cin >> d;
        trans[i] = d;
    }

    for(ll i = n; i > 0; i--) {
        ll mx = 0;
        for(ll j = m; j > 0; j--) {
            mx = max(mx, arr[i][j]);
            arr[i][j] = mx;
        }
    }

    for(ll i = m; i > 0; i--) {
        ll mx = 0;
        for(ll j = n; j > 0; j--) {
            mx = max(mx, arr[j][i]);
            arr[j][i] = mx;
        }
    }

    for(ll i = 1; i <= n; i++) {
        for(ll j = 1; j <= m; j++) {
            cout << trans[arr[i][j]];
        }
        cout << endl;
    }
}