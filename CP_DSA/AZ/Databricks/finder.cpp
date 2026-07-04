// Write your code here
#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define endl '\n'

void solve() {
    ll n; cin >> n;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    }
    if(n == 1 || n == 2) {
        for(auto x : arr) cout << x << " "; cout << endl;
        return;
    }

    vector<ll> res;
    res.push_back(arr[0]);
    for(ll i = 1; i < n-1; i++) {
        if(arr[i] > arr[i-1] && arr[i] > arr[i+1]) {
            res.push_back(arr[i]);
        }
    }
    res.push_back(arr[n-1]);

    for(auto x : res) cout << x << " "; cout << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t; cin >> t;
    while(t--) {
        solve();
    }
}