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
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    ll mn = arr[n-1];
    vector<ll> mxarr(n);
    vector<ll> mnarr(n);
    for(ll i = n-1; i >= 0; i--) {
        mn = min(mn, arr[i]);
        mnarr[i] = mn;
    }
    
    // for(auto x : mnarr) cout << x << " "; cout << endl;
    
    ll mx = arr[0];
    for(ll i = 0; i < n; i++) {
        mx = max(mx, arr[i]);
        mxarr[i] = mx;
    }
    
    // for(auto x : mxarr) cout << x << " "; cout << endl;
    
    ll ct = 1;
    for(ll i = 1; i < n; i++) {
        if(mxarr[i-1] <= mnarr[i]) ct++;
    }
    cout << ct << endl;
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
