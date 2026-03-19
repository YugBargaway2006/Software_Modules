#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n; cin >> n;
    vector<vector<int>> adj(n+1);
    for(int i = 0; i < n-1; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int rem = n;
    priority_queue<int, vector<int>, greater<int>> q;
    vector<int> indegree(n+1, 0);
    for(int i = 1; i <= n; i++) {
        indegree[i] = adj[i].size();
        if(indegree[i] == 1) {
            q.push(i);
        }
    }

    vector<int> order;
    for(int i = 0; i < n-2; i++) {
        int u = q.top(); q.pop();

        for(auto v : adj[u]) {
            if(indegree[v] > 0) {
                order.push_back(v);

                indegree[v]--;
                if(indegree[v] == 1) q.push(v);
                break;
            }
        }

        indegree[u] = 0;
    }

    for(auto u : order) {
        cout << u << " ";
    }
    cout << endl;

}