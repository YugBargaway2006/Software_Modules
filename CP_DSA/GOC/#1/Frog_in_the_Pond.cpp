// :::::::::::: VVI to remember
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> dist(n, -1);

    queue<int> q;
    q.push(0);
    dist[0] = 0;

    set<int> unvisited;
    for (int i = 1; i < n; i++)
        unvisited.insert(i);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        int R = min(n - 1, u + a[u]);

        auto it = unvisited.lower_bound(u + 1);

        while (it != unvisited.end() && *it <= R) {
            int v = *it;
            dist[v] = dist[u] + 1;
            q.push(v);

            auto erase_it = it++;
            unvisited.erase(erase_it);
        }
    }

    int Q;
    cin >> Q;

    while (Q--) {
        int x;
        cin >> x;
        cout << dist[x - 1] << '\n';
    }
}