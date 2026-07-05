#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve() {
    ll x, y, k;
    cin >> x >> y >> k;

    ll ct = 0;
    while (x != y) {
        if (x < y) swap(x, y);
        x /= k;
        ct++;
    }

    cout << ct << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}