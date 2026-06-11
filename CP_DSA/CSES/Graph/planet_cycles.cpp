// 17 : 35    ::::::: Easy, Know the concept
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

vector<int> dest;
vector<bool> vis;
vector<int> len;
queue<int> path;
int steps = 0;

void dfs(int i) {
    path.push(i);
    if(vis[i]) {
        steps += len[i];
        return;
    }
    vis[i] = true;
    steps++;
    dfs(dest[i]);
}

signed main(void) {
    int n; cin >> n;
    dest.assign(n, 0);
    vis.assign(n, false);
    len.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> dest[i];
        dest[i]--;
    }

    for(int i = 0; i < n; i++ ){
        if(vis[i]) continue;

        steps = 0;
        dfs(i);

        int dec = 1;
        while(!path.empty()) {
            if(path.front() == path.back()) dec = 0;
            len[path.front()] = steps;
            steps -= dec;
            path.pop();
        }
    }
    for(auto u : len) cout << u << " ";
    cout << endl;
}

// 17 : 45