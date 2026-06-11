// 13 : 51
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll x, n; cin >> x >> n;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    map<ll, ll> path;
    set<ll> lights;
    lights.insert(0);
    lights.insert(x);
    path[x] = 1;
    for(auto p : arr) {
        auto gt = lights.upper_bound(p);
        auto lt = prev(gt);

        ll len = *gt - *lt;

        path[len]--;
        if(path[len] == 0) path.erase(len);

        path[p - *lt]++;
        path[*gt - p]++;

        lights.insert(p);

        cout << path.rbegin()->first << " ";
    }
    cout << endl;

}