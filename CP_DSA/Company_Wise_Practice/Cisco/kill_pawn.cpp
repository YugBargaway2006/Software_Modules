#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define endl '\n'

vector<ll> dx = {-2, -1, 1, 2, 2, 1, -1, -2};
vector<ll> dy = {1, 2, 2, 1, -1, -2, -2, -1};

vector<vector<ll>> dist;

void bfs(ll sx, ll sy) {
    dist.assign(8, vector<ll>(8, 0));
    queue<pair<ll, ll>> q;
    vector<vector<bool>> vis(8, vector<bool>(8, false));
    dist[sx][sy] = 0;
    q.push({sx, sy});
    vis[sx][sy] = true;
    while(!q.empty()) {
        auto p = q.front(); q.pop();
        ll u = p.first; ll v = p.second;

        for(ll i = 0; i < 8; i++) {
            ll nx = u+dx[i];
            ll ny = v+dy[i];

            if(nx < 0 || ny < 0 || nx >= 8 || ny >= 8) continue;
            if(vis[nx][ny]) continue;
            vis[nx][ny] = true;
            dist[nx][ny] = dist[u][v] + 1;
            q.push({nx, ny});
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll sx, sy; cin >> sx >> sy;
    ll m; cin >> m;
    
    if(m == 0) { cout << 0 << endl; return 0; }
    
    vector<pair<ll, ll>> arr(m);
    for(ll i = 0; i < m; i++) {
        cin >> arr[i].first >> arr[i].second;
    } 

    vector<vector<ll>> adj(m + 1, vector<ll>(m + 1, 0));
    bfs(sx, sy);
    for(ll i = 0; i < m; i++) adj[m][i] = dist[arr[i].first][arr[i].second]; 
    for(ll i = 0; i < m; i++) {
        bfs(arr[i].first, arr[i].second);
        for(ll j = 0; j < m; j++) adj[i][j] = dist[arr[j].first][arr[j].second]; 
    }

    vector<vector<ll>> dp(1 << m, vector<ll>(m, 1e9));
    for(ll i = 0; i < m; i++) dp[1 << i][i] = adj[m][i]; 

    for(ll mask = 1; mask < (1<<m); mask++) {
        for(ll last = 0; last < m; last++) {
            if(!((mask >> last) & 1)) continue;
            
            for(ll i = 0; i < m; i++) {
                if((mask >> i) & 1) continue;
                ll nm = mask | (1 << i);
                
                dp[nm][i] = min(dp[nm][i], dp[mask][last] + adj[last][i]);
            }
        }
    }

    ll ans = 1e9;
    for(ll i = 0; i < m; i++) ans = min(ans, dp[(1 << m)-1][i]);
    
    cout << ans << endl;
}