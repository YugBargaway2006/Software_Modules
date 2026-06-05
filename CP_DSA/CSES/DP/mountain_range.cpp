// 23 : 41 :::::: Nearest Greater Element
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ll n;
vector<ll> sige, lige, arr, dp;

ll filldp(ll i) {
    if(i < 0 || i >= n) return 0;
    if(dp[i] != -1) return dp[i];
    dp[i] = 1 + max(filldp(sige[i]), filldp(lige[i]));

    return dp[i];
}


signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    arr.resize(n);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sige.resize(n), lige.resize(n);

    // Smaller
    stack<ll> s;
    sige[0] = -1;
    s.push(0);
    for(ll i = 1; i < n; i++) {
        if(arr[s.top()] > arr[i]) {
            sige[i] = s.top();
        } else {
            while(!s.empty() && arr[s.top()] <= arr[i]) {
                s.pop();
            }
            if(s.empty()) sige[i] = -1;
            else sige[i] = s.top();
        }
        s.push(i);
    }

    // for(auto u : sige) cout << u << " "; cout << endl;
    while(!s.empty()) s.pop();
    lige[n-1] = -1;
    s.push(n-1);
    for(ll i = n-1; i >=0 ; i--) {
        if(arr[s.top()] > arr[i]) {
            lige[i] = s.top();
        } else {
            while(!s.empty() && arr[s.top()] <= arr[i]) {
                s.pop();
            }
            if(s.empty()) lige[i] = -1;
            else lige[i] = s.top();
        }
        s.push(i);
    }   
    // for(auto u : lige) cout << u << " "; cout << endl;

    dp.assign(n, -1);
    ll mx = 0;
    for(ll i = 0; i < n; i++) {
        if(dp[i] == -1) filldp(i);
        mx = max(mx, dp[i]);
    }

    // for(auto u : dp) cout << u << " "; cout << endl;

    cout << mx << endl; 
}