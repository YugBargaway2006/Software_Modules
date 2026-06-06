// https://www.hackerrank.com/contests/goc-cdc-series-5/challenges/special-fruits/problem?isFullScreen=true
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
    
    ll t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        vector<vector<ll>> time(n, vector<ll>(2));
        for(ll i = 0; i < n; i++) {
            ll v, x; cin >> v >> x;
            time[i][0] = v+x; time[i][1] = v-x;
        }
        sort(time.begin(), time.end());
        // for(ll i = 0; i < n; i++) {
        //     cout << time[i][1] << " " << time[i][0] << endl;
        // }
        
        ll ct = 0;
        vector<ll> ans;
        ll i = 0;
        while(i < n) {
            ct++;
            ll cur = time[i][0];
            ans.push_back(cur);
            while(i < n && time[i][1] <= cur) {
                i++;
            }
        }
        cout << ct << endl;
        for(auto x : ans) cout << x << " "; cout << endl;        
    }
    return 0;
}
