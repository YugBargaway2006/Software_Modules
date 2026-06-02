// 17 : 20 ::::::::::: REVISE
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

signed main(void) {
    ll n; cin >> n;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ll l = 0, r = 0;
    ll ct = 0;
    map<ll, ll> freq;
    // freq[arr[0]]++;
    while(l <= r && r < n) {
        // cout << freq[arr[r]] << endl;
        if(freq[arr[r]] == 0) {
            freq[arr[r]]++;
            ct += (r - l + 1);
            // cout << l << " " << r << " " << (r - l + 1) << endl;
            r++;
        } else {
            while(freq[arr[r]] != 0 && l < r) {
                freq[arr[l]]--;
                l++;
            }
            freq[arr[r]]++;
            // cout << l << " " << r << " " << (r - l + 1) << endl;
            ct += (r - l + 1);
            r++;
        }
    }
    cout << ct << endl;
}