// 14 : 43
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

vector<vector<ll>> arr;
ll n;
vector<ll> dx = {-2, -2, -1, 1, 2, 2, 1, -1};
vector<ll> dy = {-1, 1, 2, 2, 1, -1, -2, -2};

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    arr.assign(n, vector<ll>(n, INT_MAX));

    arr[0][0] = 0;
    queue<pair<ll, ll>> q; 
    q.push({0, 0});
    while(!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for(ll i = 0; i < 8; i++) {
            ll nx = x+dx[i];
            ll ny = y+dy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if(arr[nx][ny] != INT_MAX) continue;
            arr[nx][ny] = arr[x][y] + 1;
            q.push({nx, ny});
        }
    }

    for(auto& vec : arr) {
        for(auto x : vec) cout << x << " "; cout << endl;
    }
}