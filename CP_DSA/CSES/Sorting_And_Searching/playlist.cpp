// *** 20 : 04
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n; cin >> n;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    unordered_map<ll, ll> found;
    found.reserve(n+1);
    ll count = 0;
    ll mx = 1;
    ll st = 0, en = 0;
    for(ll i = 0; i <= n-1; i++) {
        if(found.count(arr[i]) == 0) {
            count++;
            found[arr[i]] = i;
            mx = max(mx, count);
            // cout << "NF" << " " << arr[i] << " " << count << " " << mx << endl;
        }
        else if(found.count(arr[i]) != 0) {
            if(found[arr[i]] >= st) {
                st = found[arr[i]]+1;
                found[arr[i]] = i; 
                count = i - st + 1;
            } else {
                found[arr[i]] = i;
                count++;
            }
            mx = max(mx, count);
            // cout << "FO" << " " << arr[i] << " " << found[arr[i]] << " " << st << " " << count << " " << mx << endl;
        }
    }
    cout << mx << endl;
}