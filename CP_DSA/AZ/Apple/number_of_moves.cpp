// Write your code here
#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define endl '\n'

vector<ll> dy = {1, 2, 2, 1, -1, -2, -2, -1};
vector<ll> dx = {-2, -1, 1, 2, 2, 1, -1, -2};

void solve() {
    ll n; cin >> n;
    vector<vector<ll>> depth(n, vector<ll>(n, -1));

    ll sx, sy, fx, fy; cin >> sx >> sy >> fx >> fy;
    queue<pair<ll, ll>> q;
    q.push({sx, sy});
    depth[sx][sy] = 0;
    while(!q.empty()) {
        auto p = q.front(); q.pop();
        ll x = p.first;
        ll y = p.second;

        for(ll i = 0; i < 8; i++) {
            ll nx = x + dx[i];
            ll ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if(depth[nx][ny] != -1) continue;
            depth[nx][ny] = 1+depth[x][y];
            q.push({nx, ny});
        }
    }

    cout << depth[fx][fy] << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t; cin >> t;
    while(t--) {
        solve();
    }
}