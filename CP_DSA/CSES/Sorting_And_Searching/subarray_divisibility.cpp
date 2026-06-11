// 06 : 48
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
    
    vector<ll> rem(n, 0);
    rem[0] = 1;
    ll ps = 0;
    ll ct = 0;
    for(ll i = 0; i < n; i++) {
        ps += arr[i];
        if(ps < 0) ps += n * 1e9;
        ct+= rem[ps%n];
        rem[ps%n]++;
        ps %= n;
    }
    cout << ct << endl;
}