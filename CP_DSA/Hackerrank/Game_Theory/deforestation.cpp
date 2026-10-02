#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ll n;
vector<vector<ll>> arr;
vector<ll> grundy;
ll mxn = 500+1;

ll calculate(ll u, ll p) {
    if(grundy[u] != -1) return grundy[u];
    ll cur = 0;
    for(auto v : arr[u]) {
        if(v == p) continue;
        cur ^= (calculate(v, u)+1);
    }
    
    return grundy[u] = cur;
}

void solve() {
    cin >> n;
    arr.assign(n, {});
    grundy.assign(n, -1);
    
    for(ll i = 0; i < n-1; i++) {
        ll x, y; cin >> x >> y;
        x--; y--;
        arr[x].push_back(y);
        arr[y].push_back(x);
    }
    
    ll num = calculate(0, 0);
    if(num != 0) cout << "Alice" << endl;
    else cout << "Bob" << endl;
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
