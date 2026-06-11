// https://www.hackerrank.com/contests/goc-cdc-series-2/challenges/playing-with-numbers-15/problem?isFullScreen=true
// Bitset DP Boost is required.
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
    ll total = 0;
    set<ll> sum;
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
        total += arr[i];
    }
    
    sum.insert(0);
    set<ll> nsum;
    for(ll i = 0; i < n; i++) {
        for(auto s : sum) {
            nsum.insert(s + arr[i]);
            nsum.insert(s);
        }
        sum = nsum;
    }
    auto it = sum.lower_bound((total+1)/2);
    cout << *it << endl;
    
    return 0;
}
