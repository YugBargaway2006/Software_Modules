// *** 01 : 18
#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(void) {
    int n, m, q; cin >> n >> m >> q;
    // vector<vector<pair<int, int>>> adj(n+1);
    vector<vector<int>> dist(n+1, vector<int>(n+1, 1e15));
    for(int i = 1; i <= n; i++) dist[i][i] =0;
    for(int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        dist[x][y] = min(dist[x][y], z);
        dist[y][x] = min(dist[x][y], z);
    }

    for(int k = 1; k <= n; k++) {
        for(int s = 1; s <= n; s++) {
            for(int e = 1; e <= n; e++) {
                dist[s][e] = min(dist[s][e], dist[s][k] + dist[k][e]);
            }
        }
    }

    // for(int i = 1; i <= n; i++) {
    //     for(int j = 1; j <= n; j++) {
    //         cout << dist[i][j] << " ";
    //     }
    //     cout << endl;
    // } 

    for(int i = 0; i < q; i++) {
        int x, y; cin >> x >> y;
        if(dist[x][y] == 1e15) cout << -1 << endl;
        else cout << dist[x][y] << endl;
    }
}

// 01 : 28