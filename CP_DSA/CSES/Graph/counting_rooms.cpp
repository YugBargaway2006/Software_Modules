#include <bits/stdc++.h>
using namespace std;

void visall(vector<vector<int>>& adj, vector<vector<bool>>& vis, int n, int m, int i, int j) {
    if(i < 0 || i >= n || j < 0 || j >= m) return;
    if(vis[i][j] == true) return;
    if(adj[i][j] == 0) return;
    vis[i][j] = true;
    visall(adj, vis, n, m, i+1, j);
    visall(adj, vis, n, m, i-1, j);
    visall(adj, vis, n, m, i, j+1);
    visall(adj, vis, n, m, i, j-1);
}
 
signed int main(void) {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            char x; cin >> x;
            (x == '.') ? adj[i][j] = 1 : adj[i][j] = 0;
        }
    }

    vector<vector<bool>> vis(n, vector<bool>(m, false));
    int count = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(adj[i][j] == 1 && !vis[i][j]) {
                count++;
                visall(adj, vis, n, m, i, j);
            }
        }
    }
    cout << count << endl;
}