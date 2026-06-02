// 06 : 58
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, k; cin >> n >> k;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    map<ll, ll> freq;
    ll ct = 0;
    ll uni = 0;
    ll l = 0, r = 0;
    while(l <= r && r < n) {
        if(freq[arr[r]] != 0) {
            freq[arr[r]]++;
        } else {
            freq[arr[r]]++;
            uni++;
            while(uni > k) {
                freq[arr[l]]--;
                if(freq[arr[l]] == 0) uni--;
                l++;
            }
        }
        ct += (r - l + 1);
        r++;
    }
    cout << ct << endl;
}