// 13 : 29
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

    map<ll, ll> num;
    int ct = 0;
    for(int i = 0; i < n; i++) {
        auto it = num.upper_bound(arr[i]);
        if(it == num.end()) {
            num[arr[i]] += 1;
            ct++;
        } else {
            num[arr[i]] += 1;
            num[it->first]--;
            if(num[it->first] == 0) {
                // ct--;
                num.erase(it);
            }
        }
    }
    cout << ct << endl;
}