// 07 : 39
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'


signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, k; cin >> n >> k;
    vector<pair<ll, ll>> arr(n);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i].second >> arr[i].first;
    }
    sort(arr.begin(), arr.end());

    multiset<ll> mov;
    for(ll i = 0; i < k; i++) {
        mov.insert(0);
    }

    int ans = 0;
    for(auto v : arr) {
        auto it = mov.upper_bound(v.second);
        if(it == begin(mov)) continue;
        mov.erase(--it);
        mov.insert(v.first);
        ans++;
    }
    cout << ans << endl;
}