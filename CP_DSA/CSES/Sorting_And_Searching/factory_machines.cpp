// 23 : 07
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ll count(vector<ll> t, ll ct) {
    ll ans = 0;
    for(ll i = 0; i < t.size(); i++) {
        ans += (ct / t[i]);
    }
    return ans;
} 

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, x; cin >> n >> x;
    vector<ll> t(n);
    ll mv = 1e9;
    // priority_queue<vector<ll>, vector<vector<ll>>, greater<>> q;
    for(ll i = 0; i < n; i++) {
        cin >> t[i];
        mv = min(mv, t[i]);
        // q.push({t[i], i});
    }

    ll time = 0;
    ll l =0 , r = mv * x;
    while(l <= r) {
        ll mid = l + (r - l) / 2;
        bool c1 = count(t, mid-1) >= x;
        bool c2 = count(t, mid) >= x;
        // bool c3 = count(t, mid+1) > x;

        // cout << count(t, mid-1) << " " << count(t, mid) << endl;
        // cout << l << " " << mid << " " << r << endl;
        if(!c1 && c2) {
            cout << mid << endl;
            break;
        }
        if(c1 && c2) {
            // l = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    // cout << time << endl;
}