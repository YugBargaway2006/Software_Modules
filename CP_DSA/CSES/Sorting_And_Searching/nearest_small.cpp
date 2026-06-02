// 00 : 10
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

signed main(void) {
    ll n; cin >> n;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    stack<pair<ll, ll>> s;
    vector<ll> ans(n);
    for(ll i = 0; i < n; i++) {
        if(s.empty()) {
            ans[i] = 0;
            // cout << "Push1 -> " << arr[i] << " " << i << endl;
            s.push({arr[i], i});
            // cout << "Empty -> " << arr[i] << " " << i << endl;
            continue;
        }
        // cout << "Non-Empty -> " << arr[i] << " " << i << endl;
        while(!s.empty()) {
            auto [u, j] = s.top();
            if(u < arr[i]) {
                // cout << "Found -> " << u << " " << arr[i] << " " << i << endl;
                ans[i] = j+1;
                // cout << "Push2 -> " << arr[i] << " " << i << endl;
                s.push({arr[i], i});
                break;
            }
            s.pop();
        }
        if(s.empty()) {
            ans[i] = 0;
            // cout << "Push3 -> " << arr[i] << " " << i << endl;
            s.push({arr[i], i});
        }
    }
    for(auto u : ans) cout << u << " ";
    cout << endl;
}