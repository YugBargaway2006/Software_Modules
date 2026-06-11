// 14 : 31
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

vector<ll> dx = {-1,-1,-1,0,1,1,1,0};
vector<ll> dy = {-1,0,1,1,1,0,-1,-1};

void print(vector<vector<char>>& ans) {
    for(auto& v : ans) {
        for(auto c : v) cout << c; cout << endl;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, m; cin >> n >> m;
    vector<vector<char>> arr(n, vector<char>(m));
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    vector<vector<char>> ans(n, vector<char>(m, '.'));

    vector<vector<ll>> ddot(n, vector<ll>(m, 0));
    queue<pair<ll, ll>> qdot;
    vector<vector<bool>> vdot(n, vector<bool>(m, false));
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < m; j++) {
            if(arr[i][j] == '.') {
                vdot[i][j] = true;
                qdot.push({i, j});
            }
        }
    }
    if(qdot.empty()) {
        print(ans);
        return 0;
    }
    while(!qdot.empty()) {
        auto [x, y] = qdot.front(); qdot.pop();
        for(ll i= 0; i < 8; i++) {
            ll nx = x + dx[i];
            ll ny = y+dy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(vdot[nx][ny]) continue;
            if(arr[nx][ny] != '#') continue;
            qdot.push({nx, ny});
            vdot[nx][ny] = true;
            ddot[nx][ny] = ddot[x][y] + 1;
        }
    }

    vector<vector<ll>> dhash(n, vector<ll>(m, 0));
    queue<pair<ll, ll>> qhash;
    vector<vector<bool>> vhash(n, vector<bool>(m, false));
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < m; j++) {
            if(arr[i][j] == '#') {
                vhash[i][j] = true;
                qhash.push({i, j});
            }
        }
    }

    if(qhash.empty()) {
        print(ans);
        return 0;
    }
    while(!qhash.empty()) {
        auto [x, y] = qhash.front(); qhash.pop();
        for(ll i= 0; i < 8; i++) {
            ll nx = x + dx[i];
            ll ny = y+dy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(vhash[nx][ny]) continue;
            if(arr[nx][ny] != '.') continue;
            qhash.push({nx, ny});
            vhash[nx][ny] = true;
            dhash[nx][ny] = dhash[x][y] + 1;
        }
    }

    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < m; j++) {
            if(arr[i][j] == '.') {
                if(dhash[i][j] % 2 == 0)ans[i][j] = '#';
            } else {
                if(ddot[i][j] % 2 == 1) ans[i][j] = '#';
            }
        }
    }
    print(ans);
}