#include <bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define ll long long

void solve() {
    int n; cin >> n;
    if(n == 1) {
        cout << 1 << endl;
        return;
    }
    if(n == 4) {
        cout << "2 4 1 3" << endl;
        return;
    }
    if(n < 4) {
        cout << "NO SOLUTION" << endl;
        return;
    }
 
    vector<ll> ans(n);
    int i = 1, k = 0;
    while(k < n) {
        ans[k] = i;
        i++;
        k+=2;
    }
    k = 1;
    while(k < n) {
        ans[k] = i;
        i++;
        k+=2;
    }
    for(auto c : ans) cout << c <<" "; cout << endl;
}

 
 
signed main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    // int t; cin >> t;
    int t = 1;
 
    while(t--) {
        // cout << "solve called" << endl;
        solve();
    }
}