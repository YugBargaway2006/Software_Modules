// 23 : 55
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

bool isTri(ll n) {
    __int128 x = 8 * (__int128)n + 1;

    ll s = sqrt((long double)x);

    while((__int128)(s + 1) * (s + 1) <= x) s++;
    while((__int128)s * s > x) s--;

    return (__int128)s * s == x;
}

bool sumTwoSquares(ll n) {
    for(ll p = 2; p * p <= n; p++) {
        int cnt = 0;

        while(n % p == 0) {
            n /= p;
            cnt++;
        }

        if((p % 4 == 3) && (cnt & 1)) {
            return false;
        }
    }

    if(n > 1 && n % 4 == 3) {
        return false;
    }

    return true;
}

void solve() {
    ll n;
    cin >> n;

    if(isTri(n)) {
        cout << 1 << endl;
        return;
    }

    if(sumTwoSquares(8 * n + 2)) {
        cout << 2 << endl;
        return;
    }

    cout << 3 << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t;
    cin >> t;

    while(t--) {
        solve();
    }
}