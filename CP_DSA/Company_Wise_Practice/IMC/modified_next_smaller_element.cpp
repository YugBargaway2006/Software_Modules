#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define endl '\n'

ll mod = 1e9+7;

void solve() {
    ll n; cin >> n;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    stack<ll> s;
    vector<ll> nse(n);
    nse[n-1] = n;
    s.push(n-1);

    for(ll i = n-1; i >= 0; i--) {
        while(!s.empty() && arr[i] <= arr[s.top()]) {
            s.pop();
        }
        if(s.empty()) {
            nse[i] = n;
        } else {
            nse[i] = s.top();
        }
        s.push(i);
    }

    // for(auto x : nse) cout << x << " "; cout << endl;

    ll profit = 0;
    for(ll i = 0; i < n; i++) {
        if(nse[i] == n) continue;
        profit += (arr[i] - arr[nse[i]]) * (nse[i] - i);
        profit %= mod;
    }

    cout << profit << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t; cin >> t;
    while(t--) {
        solve();
    }
}