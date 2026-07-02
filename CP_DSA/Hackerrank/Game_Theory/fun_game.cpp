#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
#define endl '\n'

void solve() {
    ll n; cin >> n;
    vector<bool> done(n, false);
    vector<ll> arr(n, 0), brr(n, 0);
    vector<pair<ll, ll>> ca(n), cb(n);
    
    for(ll i = 0; i < n; i++) {
        ll x; cin >> x;
        arr[i] = x;
    }
    for(ll i = 0; i < n; i++) {
        ll x; cin >> x;
        brr[i] = x;
    }
    
    for(ll i = 0; i < n; i++) {
        ca[i] = {arr[i] + brr[i], i};
    }
    
    sort(ca.rbegin(), ca.rend());
    
    ll pa = 0, pb = 0;
    for(ll i = 0; i < n; i++) {
        if(i%2==0) pa += arr[ca[i].second];
        if(i%2==1) pb += brr[ca[i].second];
    }
    
    // for(auto p : ca) cout << p.first << " "; cout << endl;
    // cout << pa << " " << pb << endl;
    
    if(pa == pb) cout << "Tie" << endl;
    else if(pa > pb) cout << "First" << endl;
    else cout << "Second" << endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll t; cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
