// Write your code here
#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define endl '\n'

void solve() {
    ll n; cin >> n;
    vector<pair<ll, ll>> arr(n);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    sort(arr.begin(), arr.end());

    vector<pair<ll, ll>> merged;
    ll start = arr[0].first;
    ll end = arr[0].second;
    for(ll i = 1; i < n; i++) {
        if(arr[i].first >= start && arr[i].first <= end) {
            end = max(end, arr[i].second);
        } else {
            merged.push_back({start, end});
            start = arr[i].first;
            end = arr[i].second;
        }
    }
    merged.push_back({start, end});

    for(auto p : merged) {
        cout << p.first << " " << p.second << endl;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t; cin >> t;
    while(t--) {
        solve();
    }
}