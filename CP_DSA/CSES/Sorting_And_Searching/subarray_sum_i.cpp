// 00 : 26
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, x; cin >> n >> x;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ll l = 0, r = 0;
    ll ct = 0;
    ll sum = 0;
    while(l <= r && r < n) {
        sum += arr[r];
        if(sum == x) ct++;
        else if(sum < x) ;
        else {
            while(sum > x && l <= r) {
                sum -= arr[l];
                l++;
            }

            if(sum == x) ct++;
        }
        r++;
    }
    cout << ct << endl;
}