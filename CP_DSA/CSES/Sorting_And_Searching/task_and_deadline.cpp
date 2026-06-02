// 23 : 32
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n; cin >> n;
    vector<pair<ll, ll>> arr(n);;
    for(ll i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr.begin(), arr.end());

    ll ct = 0;
    ll rev = 0;
    for(auto [tr, d] : arr) {
        ct += tr;
        rev += (d - ct);
    }
    cout << rev << endl;
}
