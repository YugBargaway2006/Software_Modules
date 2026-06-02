// 00 : 26   :::: Understand the LOGIC
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, x; cin >> n >> x;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ll ps = 0;
    ll ans = 0;
    map<ll, ll> sums;
    sums[0] = 1;
    for(auto a : arr) {
        ps += a;
        ans += sums[ps - x];
        sums[ps]++;
    }
    cout << ans << endl;
}