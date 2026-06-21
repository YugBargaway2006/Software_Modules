// Write your code here
#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define endl '\n'

void solve() {
    ll n, m; cin >> n >> m;
    map<ll, ll> pr;
    vector<ll> arr(m), brr(m);
    for(ll i = 0; i < m; i++) {
        cin >> arr[i];
    }
    for(ll i = 0; i < m; i++) {
        cin >> brr[i];
    }

    for(ll i = 0; i < m; i++) {
        ll a = arr[i]-1; ll b = brr[i]-1;
        if(a < b) swap(a, b);
        pr[a] = max(pr[a], b);
        // cout << 
    }

    ll ct = 0;
    ll l = -1;
    for(ll r = 0; r < n; r++) {
        if(pr.count(r) != 0) {
            l = max(l, pr[r]);
        }
        ct += (r - l);
        // cout << l << " " << r << " " << ct << endl;
    }
    cout << ct << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t; cin >> t;
    while(t--) {
        solve();
    }
}