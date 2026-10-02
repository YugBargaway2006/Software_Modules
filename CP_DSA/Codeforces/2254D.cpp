/*
    Solution: 
    1. Divide by levels, count the freq of each level, 
    2. Value of 1 level = (next_level - curr_level) / count_curr_level
    3. Make sure strictly increasing
    4. Make sure zero level exist. Make sure no fractions
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve() {
    ll n; cin >> n;
    vector<ll> arr(n);
    map<ll, ll> levels;
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
        levels[arr[i]]++;
    }

    if(levels.begin()->first != 0) {
        cout << -1 << endl;
        return;
    }

    map<ll, ll> rel;
    ll curr = 0;
    for(auto it = levels.begin(); it != prev(levels.end()); it++) {
        ll lv = it->first;
        ll nlv = next(it)->first;
        ll lc = it->second;

        if((nlv - lv) % lc != 0) {
            cout << -1 << endl;
            return;
        }

        ll val = (nlv - lv) / lc;
        if(val <= curr) {
            cout << -1 << endl;
            return;
        }

        rel[lv] = (nlv - lv) / lc;
        curr = rel[lv];
    }

    // cout << levels[prev(levels.end())->first] << endl;
    rel[prev(levels.end())->first] = curr+1;

    vector<ll> brr(n);
    for(ll i = 0; i < n; i++) {
        brr[i] = rel[arr[i]];
    }

    for(auto x : brr) cout << x << " "; cout << endl;

}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t; cin >> t;
    while(t--) {
        solve();
    }
}