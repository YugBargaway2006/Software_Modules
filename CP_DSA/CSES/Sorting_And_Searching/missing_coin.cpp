// *** 19 : 23
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n; cin >> n;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());

    ll val = 0;
    for(ll i = 0; i < n; i++) {
        if(arr[i] > val+1) {
            cout << val+1 << endl;
            return 0;
        }
        val += arr[i];
    }
    cout << val+1 << endl;
}