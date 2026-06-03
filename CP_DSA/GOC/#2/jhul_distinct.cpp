// http://hackerrank.com/contests/goc-cdc-series-2/challenges/jhul-and-distinct-numbers/problem?isFullScreen=true
// 12 : 48  ::::::: REVISE
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
    ll mxn = 3e5+1;
    vector<ll> arr(n);
    set<ll> s;
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
        // cerr << arr[i] << " ";
        s.insert(arr[i]);
    }       
    // cerr << endl;
    
    unordered_map<ll, ll> freq;
    ll ans = n;
    ll have = 0, l = 0;
    for(ll r = 0; r < n; r++) {
        freq[arr[r]]++;
        if(freq[arr[r]] == 1) {
            have++;
        }
        
        while(have == s.size()) {
            ans = min(ans, r-l+1);
            freq[arr[l]]--;
            if (freq[arr[l]] == 0)
                have--;
            l++;
        }
    }
    
    cout << ans << endl;
    
    
    
    
    return 0;
}
