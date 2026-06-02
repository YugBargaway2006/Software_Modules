// 22 : 52
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n; cin >> n;
    vector<pair<ll, ll>> arr(n);
    priority_queue<vector<ll>, vector<vector<ll>>, greater<>> q;
    for(ll i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
        q.push({arr[i].first, 0, i});
        q.push({arr[i].second, 1, i});
    }
    // sort(arr.begin(), arr.end());
    // Sort based on asc on dept
    // Make a queue to have rooms
    queue<ll> rooms;
    vector<ll> allo(n);
    // allo[0] = 1;

    ll ct = 1;
    while(!q.empty()) {
        auto vec = q.top(); q.pop();
        ll t = vec[0];
        ll in = vec[1];
        ll i = vec[2];

        // cout << t << " " << i << " " << in << endl;
        
        if(in == 0) {
            if(rooms.empty()) {
                allo[i] = ct;
                // cout << ct << endl;
                ct++;
            } else {
                ll u = rooms.front(); rooms.pop();
                allo[i] = u;
            }
        }
        if(in == 1) {
            rooms.push(allo[i]);
        }
    }
    cout << ct-1 << endl;
    for(auto u : allo) cout << u << " ";
    cout << endl;
}

// 23 : 07