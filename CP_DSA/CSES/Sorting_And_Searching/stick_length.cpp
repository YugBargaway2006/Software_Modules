// *** 17 : 25 ::::::::: REVISE
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

signed main(void) {
    ll n; cin >> n;
    // ll s = 0; 
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
        // s += arr[i];
    }

    sort(arr.begin(), arr.end());

    ll med =  (n%2 == 0) ? (arr[n/2-1] + arr[n/2]) / 2 : arr[n/2];
    ll ans = 0;
    for(ll i = 0; i < n; i++) ans += abs(arr[i] - med);
    cout << ans << endl;
}