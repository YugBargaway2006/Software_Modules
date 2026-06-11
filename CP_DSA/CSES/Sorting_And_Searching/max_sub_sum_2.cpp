// 07 : 39
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n,a,b; cin >> n >> a >> b;
    vector<ll> arr(n+1);
    vector<ll> pre(n+1, 0);
    for(ll i = 1; i <= n; i++) {
        cin >> arr[i];
        pre[i] = pre[i-1] + arr[i];
    }

    ll mx = -1e15;
    set<pair<ll, ll>> sums;
    for(ll i = a; i <= b; i++) {
        sums.insert({pre[i], i});
    }
    for(ll i = 1; i + a - 1 <= n; i++) {
        auto it = sums.rbegin();
        ll sum = it->first;
        mx = max(mx, sum - pre[i-1]);
        if(i+a-1 < n) sums.erase({pre[i+a-1], i+a-1});
        if(i+b-1 < n) sums.insert({pre[i+b], i+b});
    }

    cout << mx << endl;
}