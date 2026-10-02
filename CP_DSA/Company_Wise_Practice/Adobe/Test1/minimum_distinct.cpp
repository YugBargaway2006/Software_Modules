// Write your code here
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve() {
    ll n, m; cin >> n >> m;
    vector<ll> arr(n);
    map<ll, ll> freq;
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
        freq[arr[i]]++;
    }

    priority_queue<ll, vector<ll>, greater<>> q;
    for(auto it : freq) {
        q.push(it.second);
    }

    while(m >= q.top()) {
        m -= q.top();
        q.pop();
    }
    cout << q.size() << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t; cin >> t;
    while(t--) {
        solve();
    }
}