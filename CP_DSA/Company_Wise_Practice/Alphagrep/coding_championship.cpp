// Write your code here
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ll bits = 60;
vector<ll> p2(61, 0);
ll mod = 1e9+7;

void solve() {
    ll n; cin >> n;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    __int128 ct = 0;
    for(ll i = 0; i < bits; i++) {
        ll c0 = 0, c1 = 0;
        for(ll j = 0; j < n; j++) {
            if(arr[j] % 2 == 0) c0++;
            else c1++;
            arr[j] /= 2;
        }

        __int128 val = (c0*c1) % mod;
        val = (val*p2[i])% mod;
        ct = (ct + val) % mod;

        // cout << c0 << " " << c1 << " " << sum << " " << b << " " << carry << " " << ct << endl;
    }
    ll ans = ct % mod;
    cout << ans << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    p2[0] = 1;
    for(ll i = 1; i < 61; i++) {
        p2[i] = (p2[i-1] * 2) % mod;
    }

    ll t; cin >> t;
    while(t--) {
        solve();
    }
}