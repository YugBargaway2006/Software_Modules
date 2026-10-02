#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

bool check(vector<pair<ll, ll>>& arr, ll k, ll x) {
    ll n = arr.size();
    ll md = 1e12;
    ll mR = -1;
    ll ch = 0;
    for(ll i = 0; i < n; i++) {
        if(arr[i].first >= mR) {
            ch++;
            mR = max(mR, arr[i].second + x);
        }
    }
    return ch >= k;
}

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, k; cin >> n >> k;
    vector<pair<ll, ll>> arr(n);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    sort(arr.begin(), arr.end(), [](pair<ll, ll> a, pair<ll, ll> b) {
        if(a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    });

    ll x = 0;
    ll mR = -1;
    for(ll i = 0; i < n; i++) {
        if(arr[i].first > mR) {
            x++;
            mR = max(mR, arr[i].second);
        }
    }

    if(x < k) {
        cout << -1 << endl;
        return 0;
    }

    // sort(arr.begin(), arr.end());

    ll l = 0, r = 1e12;
    while(l <= r) {
        ll mid = l + (r - l) / 2;
        bool c1 = check(arr, k, mid);
        bool c2 = check(arr, k, mid+1);

        if(c1 && !c2) {
            cout << mid << endl;
            break;
        } else if(c1 && c1) {
            l = mid+1;
        } else {
            r = mid-1;
        }
    }
}