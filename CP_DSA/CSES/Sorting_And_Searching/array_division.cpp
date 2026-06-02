// 07 : 10   ::::: Remember the Binary Search Logic
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

bool check(vector<ll>& arr, ll n, ll target, ll k) {
    // cout << target << endl;
    ll num = 0;
    ll i = 0;
    while(i < n) {
        ll sum = arr[i];
        i++;
        while(i < n && sum + arr[i] <= target) {
            sum += arr[i];
            i++;
        }
        if(sum <= target) num++;
        if(sum > target) {
            return false;
        }
    }
    return num <= k;
}

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, k; cin >> n >> k;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ll l = 0, r = 1e15;
    while(l <= r) {
        ll mid = l + (r - l) / 2;
        bool c1 = check(arr, n, mid-1, k);
        bool c2 = check(arr, n, mid, k);

        // cout << l << " " << mid << " " << r << endl;
        if(!c1 && c2) {
            cout << mid << endl; break;
        }
        if(c1 && c2) {
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
}