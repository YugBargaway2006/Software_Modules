// https://www.hackerrank.com/contests/goc-cdc-series-3/challenges/sxcwc/problem?isFullScreen=true
// ::: Just 1 fix required
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
    
    ll n, k; cin >> n >> k;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    vector<ll> odds;
    odds.push_back(-1);
    for(ll i = 0; i < n; i++) {
        if(arr[i]%2==1) odds.push_back(i);
    }
    odds.push_back(n);
    // for(auto x : odds) cout << x << " "; cout << endl;
    ll ans = 0;
    ll m = odds.size();
    for(ll i = 1; i+k < m; i++) {
        ll left = odds[i] - odds[i - 1];    // Help solved the problem
        ll right = odds[i + k] - odds[i + k - 1];
        ans += left * right;
    }
    cout << ans << endl;
    return 0;
}
