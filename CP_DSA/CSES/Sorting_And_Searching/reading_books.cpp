// 23 : 32   ::::::: REVISE
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n; cin >> n;
    vector<ll> t(n);
    ll mx = 0;
    ll sum = 0;
    for(ll i = 0; i < n; i++) {
        cin >> t[i];
        sum += t[i];
        mx = max(mx, t[i]);
    }
    if(sum - mx > mx) cout << sum << endl;
    else cout << 2*mx << endl;
}
