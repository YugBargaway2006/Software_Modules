// 00 : 04
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, k; cin >> n >> k;
    vector<ll> arr(k);
    for(ll i = 0; i < k; i++) {
        cin >> arr[i];
    }

    ll ans = 0;
    for(ll i = 1; i < 1<<k; i++) {
        ll sb = 0;
        __int128 num = 1;
        bool ok = true;
        for(ll j = 0; j < k; j++) {
            if((i & 1 << j) != 0) {
                sb++;
                num *= arr[j];
                if(num > n) {
                    ok = false;
                    break;
                }
            }
        }
        if(!ok) continue;
        bool add = (sb % 2 == 1);
        ans += (add) ? n / num : -n / num;
    }
    cout << ans << endl;
}