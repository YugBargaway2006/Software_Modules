// Write your code here
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

void solve() {
    ll n; cin >> n;
    vector<ll> arr(n);
    ll c0 = 0, c1 = 0;
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
        if(arr[i] == 0) c0++;
        else c1++;
    }

    if(c0 > c1) {
        for(ll i = 0; i < n; i++) {
            arr[i] = 1 - arr[i];
        }
    }
    
    vector<ll> pre1(n, 0), suf1(n, 0);
    for(ll i = 0; i < n; i++) {
        pre1[i] = static_cast<ll>(arr[i] == 1);
        if(i > 0) pre1[i] += pre1[i-1];
    }

    for(ll i = n-1; i >= 0; i--) {
        suf1[i] = static_cast<ll>(arr[i] == 1);
        if(i < n-1) suf1[i] += suf1[i+1];
    }

    ll cpre = 0;
    ll csuf = 0;
    for(ll i = 0; i < n; i++) {
        if(arr[i] == 0) {
            cpre += pre1[i];
            csuf += suf1[i];
        }
    }

    cout << min(cpre, csuf) << endl;
}


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t; cin >> t;
    while(t--) {
        solve();
    }
}