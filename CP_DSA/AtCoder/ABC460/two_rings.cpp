// 14 : 31
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve() {
    ll x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

    ll dist = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
    ll d2 = (r1+r2)*(r1+r2);
    ll d3 = (r1-r2)*(r1-r2);

    // cerr << dist << " " << d2 << endl;

    if(dist <= d2 && d3 <= dist) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t; cin >> t;
    while(t--) {
        solve();
    }
}