// 17 : 34    ::::   Revise the formulation
// 17 : 34
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n; cin >> n;
    map<ll, ll> freq;
    for(ll i = 0; i < n; i++) {
        int x; cin >> x;
        freq[x]++;
    }

    ll mod = 1e9 + 7;

    int ct = 1;
    for(auto [val, count] : freq) {
        ct = (ct * (count+1)) % mod;
    }
    cout << (ct - 1 + mod) % mod << endl;
}