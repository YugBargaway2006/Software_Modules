// 20 : 11
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve() {
    ll x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    ll cross =
        (x2 - x1) * (y3 - y1) -
        (y2 - y1) * (x3 - x1);

    if(cross > 0) cout << "LEFT" << endl;
    else if(cross < 0) cout << "RIGHT" << endl;
    else cout << "TOUCH" << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t; cin >> t;
    while(t--) {
        solve();
    }
}