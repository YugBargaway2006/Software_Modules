// :::::::::::::::::::  Full Revision Required (Diagonal Approach)
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];

    string ans;
    ans.reserve(2 * n - 1);
    ans += grid[0][0];

    vector<pair<int,int>> curr, nxt;
    curr.push_back({0, 0});

    vector<vector<int>> vis(n, vector<int>(n, 0));
    int timer = 1;

    for (int step = 0; step < 2 * n - 2; step++) {
        char best = 'Z' + 1;

        for (auto [x, y] : curr) {
            if (x + 1 < n) best = min(best, grid[x + 1][y]);
            if (y + 1 < n) best = min(best, grid[x][y + 1]);
        }

        ans += best;
        nxt.clear();
        timer++;

        for (auto [x, y] : curr) {
            if (x + 1 < n && grid[x + 1][y] == best && vis[x + 1][y] != timer) {
                vis[x + 1][y] = timer;
                nxt.push_back({x + 1, y});
            }

            if (y + 1 < n && grid[x][y + 1] == best && vis[x][y + 1] != timer) {
                vis[x][y + 1] = timer;
                nxt.push_back({x, y + 1});
            }
        }

        curr.swap(nxt);
    }

    cout << ans << '\n';
}