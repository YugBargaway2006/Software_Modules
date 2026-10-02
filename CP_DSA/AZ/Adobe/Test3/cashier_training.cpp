// Write your code here
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve() {
    ll n, q; cin >> n >> q;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    } 

    vector<ll> prefix(n, 0);
    for(ll i = 0; i < n; i++) {
        prefix[i] = arr[i];
        if(i > 0) prefix[i] += prefix[i-1];
    }

    while(q--) {
        ll a, b; cin >> a >> b;
        a--; b--;
        ll ans = prefix[b];
        if(a > 0) ans -= prefix[a-1];
        cout << ans << endl;
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