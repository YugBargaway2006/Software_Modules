#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define endl '\n'

void solve() {
    ll n, val; cin >> n >> val;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<ll> ct(n, 0);
    map<ll, pair<ll, ll>> idx;

    ll c2 = 0;
    for(ll i = 0; i < n; i++) {
        if(arr[i] == val) c2++;
        else if(idx.count(arr[i]) == 0) {
            idx[arr[i]] = {i, c2};
            ct[i] = 1;
        } else {
            ct[i] = max(1LL, ct[idx[arr[i]].first] + 1 - c2 + idx[arr[i]].second);
            idx[arr[i]] = {i, c2};
        }
    }

    ll mx = 1;
    for(ll i = 0; i < n; i++) {
        // cout << ct[i] << " ";
        mx = max(mx, ct[i] + c2);
    }
    cout << mx << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t; cin >> t;
    while(t--) {
        solve();
    }
}

