// https://www.hackerrank.com/contests/goc-cdc-series-2/challenges/team-satisfaction/problem?isFullScreen=true
// :::: Easy Greedy
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


#define endl '\n'
#define ll long long

void solve() {
    ll n, k, lim; cin >> n >> k >> lim;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    
    ll ans = 0;
    ll l = 0;
    for(ll r = 0; r < n; r++) {
        if((r-l+1 > k) || (arr[r] - arr[l] > lim)) {
            ans++;
            l = r;
        }
    }
    ans++;
    cout << ans << endl;
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
