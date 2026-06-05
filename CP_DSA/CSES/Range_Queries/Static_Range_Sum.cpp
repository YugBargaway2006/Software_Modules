// 19 : 45
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n,q;
    cin >> n >> q;
    vector<ll> arr(n), pre(n);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
        pre[i] = arr[i];
        if(i > 0) pre[i] += pre[i-1];
    }

    while(q--) {
        ll a, b; cin >> a >> b;
        a--; b--;
        ll ans = pre[b];
        if(a > 0) ans -= pre[a-1];
        cout << ans << endl;
    }
}