// 16 : 31
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

class DSU {
    vector<int> parent, rank;

public:
    DSU(int n) {
        parent.assign(n+1, -1);
        rank.assign(n+1, -1);

        for(int i = 1; i <= n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int find(int i) {
        return (parent[i] == i) ? i : (parent[i] = find(parent[i]));
    }

    void unite(int x, int y) {
        int s1 = find(x), s2 = find(y);

        if(s1 != s2) {
            if(rank[s1] < rank[s2]) parent[s1] = s2;
            else if(rank[s1] > rank[s2]) parent[s2] = s1;
            else parent[s2] = s1, rank[s1]++;
        }
    }
};

signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<vector<int>> edges;
    for(int i = 0; i < m ;i++) {
        int x, y, z; cin >> x >> y >> z;
        edges.push_back({z, x, y});
        edges.push_back({z, y, x});
    }

    sort(edges.begin(), edges.end());
    DSU dsu(n);
    int cost = 0, count = 0;
    for(auto& vec : edges) {
        int u = vec[1];
        int v = vec[2];
        int w = vec[0];

        if(dsu.find(u) != dsu.find(v)) {
            dsu.unite(u, v);
            cost += w;
            if(++count == n-1) break;
        }
    }

    if(count != n-1) cout << "IMPOSSIBLE" << endl;
    else cout << cost << endl;
}