// Write your code here
#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define endl '\n'

void solve() {
    ll n; cin >> n;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<ll> sum(7, 0);
    sum[0] = 1;
    ll mod = 1e9+7;

    for(ll i = 0; i < n; i++) {
        vector<ll> ns = sum;
        ll cur = arr[i];
        for(ll j = 0; j < 7; j++) {
            ns[(j+cur)%7] = (ns[(j+cur)%7] + sum[j]) % mod;
        }
        sum = ns;
    }
    cout << sum[0] << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t; cin >> t;
    while(t--) {
        solve();
    }
}