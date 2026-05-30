#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long 
#define endl '\n'


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n; cin >> n;
    vector<ll> arr(n);
    for(ll i =  0; i < n; i++) {
        cin >> arr[i];
    }
    
    vector<ll> mxrr = arr;
    for(ll i = n-2; i>= 0; i--) {
        mxrr[i] = max(mxrr[i], mxrr[i+1]);
    }
    
    // for(auto x : mxrr) cout << x << " "; cout << endl;
    
    ll ans = 0;
    for(ll i = 0; i < n; i++) {
        ans = max(ans, mxrr[i] - arr[i]);
    }
    cout << ans << endl;
    
    return 0;
}
