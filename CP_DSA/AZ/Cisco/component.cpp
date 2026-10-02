// Write your code here
#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define endl '\n'

vector<ll> dx = {-1, 0, 1, 0};
vector<ll> dy = {0, 1, 0, -1};
vector<pair<ll, ll>> cur;

ll dfs(vector<vector<ll>>& arr, vector<vector<bool>>& vis, int x, int y, ll& sz) {
    if(vis[x][y]) return 0;
    if(arr[x][y] == 1) return 0;
    vis[x][y] = true;
    cur.push_back({x, y});
    sz++;
    for(ll i = 0; i < 4; i++) {
        ll nx = x+dx[i];
        ll ny = y+dy[i];

        if(nx < 0 || ny < 0 || nx >= arr.size() || ny >= arr[0].size()) continue;
        if(vis[nx][ny]) continue;

        dfs(arr, vis, nx, ny, sz);
    }

    
    return sz;
}

void solve() {
    ll n, m; cin >> n >> m;
    vector<vector<ll>> arr(n, vector<ll>(m, 0));
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    vector<vector<bool>> vis(n, vector<bool>(m, false));
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < m; j++) {
            if(!vis[i][j] && !(arr[i][j] == 1)) {
                ll sz = 0;
                cur.clear();
                dfs(arr, vis, i, j, sz);
                for(auto p : cur) {
                    ll x = p.first;
                    ll y = p.second;
                    arr[x][y] = (sz == 1) ? 0 : sz;
                }
            }
        }
    }

    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
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