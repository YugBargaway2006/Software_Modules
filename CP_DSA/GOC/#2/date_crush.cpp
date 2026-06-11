// https://www.hackerrank.com/contests/goc-cdc-series-2/challenges/date-with-the-crush/problem?isFullScreen=true
// 06 : 55
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

vector<ll> dx = {-1, 0, 1, 0};
vector<ll> dy = {0, 1, 0, -1};
ll n, m;
vector<vector<char>> adj;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    adj.assign(n, vector<char>(m));
    ll si, sj, fi, fj;
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < m; j++) {
            cin >> adj[i][j];
            if(adj[i][j] == 'R') {
                si = i; sj = j;
            }
            if(adj[i][j] == 'E') {
                fi = i; fj = j;
            }
        }
    }
    
    queue<pair<ll, ll>> q;
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<vector<ll>> depth(n, vector<ll>(m, 0));
    q.push({si, sj});
    vis[si][sj] = true;
    while(!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for(ll i = 0; i < 4; i++) {
            ll nx = x+dx[i];
            ll ny = y+dy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(vis[nx][ny]) continue;
            if(adj[nx][ny] == 'P') continue;
            vis[nx][ny] = true;
            q.push({nx, ny});
            depth[nx][ny] = depth[x][y]+1;
        }
    }
    
    cout << depth[fi][fj] << endl;
    
    return 0;
}
