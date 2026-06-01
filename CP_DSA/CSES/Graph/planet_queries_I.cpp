// 14 : 22  :::::::: MUST REVISE
#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define endl '\n'

const int maxN = 2e5+5;
const int maxD = 30;

signed main(void) { 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q; cin >> n >> q;
    vector<vector<int>> parent(n+1, vector<int>(maxD));

    for(int i = 1; i <= n; i++) {
        cin >> parent[i][0];
    }

    for(int d = 1; d < maxD; d++) {
        for(int i = 1; i <= n; i++) {
            parent[i][d] = parent[parent[i][d-1]][d-1];
        }
    }

    while(q--) {
        int a, d; cin >> a >> d;
        for(int i = 0; i < maxD; i++) {
            if(d & (1 << i)) a = parent[a][i];
        }
        cout << a << endl;
    }
}