// 16 : 50
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

class DSU {
private:
    vector<int> parent, size;

public:
    DSU(int n) {
        parent.resize(n+1);
        size.resize(n+1);

        for(int i = 1; i <= n ;i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find(int n) {
        return (parent[n] == n) ? n : (parent[n] = find(parent[n]));
    }

    int sz(int n) {
        return size[find(n)];
    }

    void unite(int a, int b) {
        int s1 = find(a), s2 = find(b);

        if(size[s1] < size[s2]) {
            parent[s1] = s2;
            size[s2] += size[s1];
        } else {
            parent[s2] = s1;
            size[s1] += size[s2]; 
        } 
    }
};

signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    int count = n;
    int mx = 1;

    DSU dsu(n);
    while(m--) {
        int x, y; cin >> x >> y;
        if(dsu.find(x) == dsu.find(y)) {
            cout << count << " " << mx << endl;
        } else {
            dsu.unite(x, y);
            count--;
            mx = max(mx, dsu.sz(x));
            cout << count << " " << mx << endl;
        }
    }
}

// 17 : 00