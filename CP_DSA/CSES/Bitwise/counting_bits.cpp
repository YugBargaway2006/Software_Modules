// 17 : 12
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n; cin >> n;
    vector<ll> p(52, 1);
    for(ll i = 1; i < 52; i++) p[i] = 2*p[i-1];
    ll ans = 0;
    ll lg = 52;
    if(n % 2 == 0) ans += (n/2);
    else ans += (n+1)/2;
    for(ll i = 1; i < lg; i++) {
        if(n & (1LL << i)) {
            ll pro = (n - p[i]) / p[i];
            ans += (pro * p[i-1]);
            // cout << ans << endl;
            ans += (n % p[i]) + 1;
        } else {
            ll pro = n / p[i];
            ans += (pro * p[i-1]);
        }
    }
    cout << ans << endl;
}