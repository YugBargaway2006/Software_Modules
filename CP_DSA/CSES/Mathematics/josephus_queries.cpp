// 13 : 49  :::::::: REVISE
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ll solve(ll n, ll k) {
    if (n == 1) return 1;

    ll first = n / 2;  // removed in first pass: 2,4,6,...

    if (k <= first) {
        return 2 * k;
    }

    k -= first;

    if (n % 2 == 0) {
        // survivors: 1,3,5,...
        return 2 * solve(n / 2, k) - 1;
    } else {
        // cyclic shift because after removing evens, next starts at 1
        ll x = solve((n + 1) / 2, k);
        if (x == 1) return n;
        return 2 * x - 3;
    }
}

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t; cin >> t;
    while(t--) {
        ll n, k; cin >> n >> k;
        cout << solve(n, k) << endl;
    }
}