// 14 : 10   :::::::: Revise
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve() {
    ll n, a, b; cin >> n >> a >> b;
    if (a + b > n || ((a == 0) ^ (b == 0))) {
        cout << "NO\n";
        return;
    }

    vector<ll> arr(n+1), brr(n+1);
    for(ll i = 1; i <= n; i++) {
        arr[i] = brr[i] = i;
    }

    for (ll i = 1; i <= (a+b); i++) {
        brr[i] = ((i + a - 1) % (a+b)) + 1;
    }

    cout << "YES" << endl;
    for(ll i=1;i<=n;i++) cout << arr[i] << " "; cout << endl;
    for(ll i=1;i<=n;i++) cout << brr[i] << " "; cout << endl;
}

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t; cin >> t;
    while(t--) {
        solve();
    }
}