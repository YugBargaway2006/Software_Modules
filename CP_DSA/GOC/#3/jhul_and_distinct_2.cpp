// https://www.hackerrank.com/contests/goc-cdc-series-3/challenges/jhul-and-distinct-numbers-2/problem?isFullScreen=true
// 08 : 01
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
    ios::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;
    // vector<ll> arr(n), brr(n);
    set<ll> nums;
    for(ll i = 0; i < n; i++) {
        // cin >> arr[i];
        ll x; cin >> x;
        nums.insert(x);
    }
    set<ll> nums2;
    for(ll i = 0; i < n; i++) {
        // cin >> brr[i];
        ll x; cin >> x;
        // if(nums.count(x) != 0) continue;
        nums2.insert(x);
    }
    
    vector<ll> ans;
    for(auto x : nums) {
        if(nums2.count(x) == 0) ans.push_back(x);
    }
    for(auto x : nums2) {
        if(nums.count(x) == 0) ans.push_back(x);
    }
    sort(ans.begin(), ans.end());
    for(auto x : ans) cout << x << " "; cout << endl;
    return 0;
}
