// https://www.hackerrank.com/contests/goc-cdc-series-7/challenges/a-town-without-me/problem?isFullScreen=true

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
    
    ll mxn = (1 << 20);
    ll bits = 20;
    ll n, Q; cin >> n >> Q;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    vector<bool> submask(mxn, false);
    queue<ll> q;
    for(ll i = 0; i < n; i++) {
        q.push(arr[i]);
        submask[arr[i]] = true;
    }
    
    while(!q.empty()) {
        ll u = q.front(); q.pop();
        for(ll i = 0; i < bits; i++) {
            ll newmask = (u | (1 << i));
            if(submask[newmask]) continue;
            submask[newmask] = true;
            q.push(newmask);
        }
    }
    
    vector<bool> supermask(mxn, false);
    // q.clear();
    for(ll i = 0; i < n; i++) {
        q.push(arr[i]);
        supermask[arr[i]] = true;
    }
    
    while(!q.empty()) {
        ll u = q.front(); q.pop();
        for(ll i = 0; i < bits; i++) {
            ll newmask = (u & (~(1 << i)));
            if(supermask[newmask]) continue;
            supermask[newmask] = true;
            q.push(newmask);
        }
    }
    
    while(Q--) {
        ll x; cin >> x;
        if(submask[x] || supermask[x]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    
    return 0;
}