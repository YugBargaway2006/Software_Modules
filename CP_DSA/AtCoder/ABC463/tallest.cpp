#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'


signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n; cin >> n;
    vector<pair<ll, ll>> arr(n);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i].second >> arr[i].first;
    }

    sort(arr.begin(), arr.end());

    ll mx = 0;
    for(ll i = n-1; i >= 0; i--) {
        mx = max(mx, arr[i].second);
        arr[i].second = mx;
    }

    map<ll, ll> ht;
    for(ll i = 0; i < n; i++) {
        ht[arr[i].first] = arr[i].second;
    }

    ll q; cin >> q;
    while(q--) {
        ll t; cin >> t;
        auto it = ht.upper_bound(t);
        cout << it->second << endl;
    }

}