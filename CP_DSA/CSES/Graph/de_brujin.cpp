// 17 : 53  (Create all number nodes and connect and do Eulerian Path), 
// edge : u -> (u * 2 + {1 , 0}) % (2 raised to k-1 )
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    if(n == 1) {
        cout << "01" << endl;
        return 0;
    }

    vector<vector<int>> adj(1 << (n-1));
    for(int u = 0; u < (1 << (n-1)); u++) {
        int v = (u << 1) % (1 << (n-1));
        adj[u].push_back(v);
        adj[u].push_back(v | 1);
    }

    stack<int> todo;
    todo.push(0);
    vector<int> path;
    while(!todo.empty()) {
        int node = todo.top();
        if(!adj[node].empty()) {
            todo.push(adj[node].back());
            adj[node].pop_back();
        } else {
            path.push_back(node & 1);
            todo.pop();
        }
    }

    for (int i = 0; i < n - 2; i++) { path.push_back(0); }

	for (int digit : path) { cout << digit; }
	cout << endl;
}