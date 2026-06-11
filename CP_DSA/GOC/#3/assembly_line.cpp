// https://www.hackerrank.com/contests/goc-cdc-series-3/challenges/assembly-line/problem?isFullScreen=true
// 07 : 30
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n; cin >> n;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    } 
    
    vector<ll> pl(n, -1);
    stack<ll> s;
    for(ll i = 0; i < n; i++) {
        while(!s.empty() && arr[s.top()] < arr[i]) {
            s.pop();
        }
        if(s.empty()) {
            pl[i] = -1;
            s.push(i);
        } else {
            pl[i] = s.top();
            s.push(i);
        }
    }
    
    // for(auto x : pl) cout << x << " "; cout << endl;
    ll ans = 0;
    for(ll i = 0; i < n; i++) {
        if(pl[i] == -1) ans += i;
        else ans += i-pl[i]-1;
    }
    cout << ans << endl;
    
    return 0;
}
