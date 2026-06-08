// ::::::::::: REVISE THE FORMULATION
#include <bits/stdc++.h>   
using namespace std;
 
int diameter = INT_MIN;
 
int dfs(vector<vector<pair<int, int>>>& adj, int u, int parent) {
    int best1 = 0, best2 = 0;
 
    for(auto v : adj[u]) {
        if(v.first == parent) continue;
 
        int child = dfs(adj, v.first, u) + v.second;
        child = max(child, v.second);
        if(child > best1) {
            best2 = best1;
            best1 = child;
        } else if(child > best2) {
            best2 = child;
        }
    }
 
    diameter = max(diameter, best1);
    diameter = max(diameter, best1+best2);
    
    return best1;
 
}
 
int main(void) {
    int n; cin >> n;
    vector<vector<pair<int,int>>> adj(n+1);
 
    for(int i = 0; i < n-1; i++) {
        int x, y, z; cin >> x >> y;
        z = 1;
        adj[x].push_back({y,z});
        adj[y].push_back({x,z});
    }
 
    dfs(adj, 1, 0);
    cout << diameter << endl;
}