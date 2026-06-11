#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<vector<pair<int,int>>> adj;
vector<vector<int>> capacity;
vector<pair<int,int>> edges;
int n,m;

int max_flow(int s,int t){
    vector<int> parent(n);

    auto bfs = [&]() {
        fill(parent.begin(), parent.end(), -1);

        queue<int> q;
        q.push(s);
        parent[s] = -2;

        while(!q.empty()){
            int u=q.front();
            q.pop();

            for(auto [v,_]:adj[u]){
                if(parent[v]!=-1) continue;
                if(capacity[u][v]==0) continue;

                parent[v]=u;
                q.push(v);
            }
        }

        return parent[t]!=-1;
    };

    int flow=0;

    while(bfs()){
        int cf=LLONG_MAX;

        for(int v=t;v!=s;v=parent[v])
            cf=min(cf,capacity[parent[v]][v]);

        for(int v=t;v!=s;v=parent[v]){
            capacity[parent[v]][v]-=cf;
            capacity[v][parent[v]]+=cf;
        }

        flow+=cf;
    }

    return flow;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>m;

    adj.assign(n,{});
    capacity.assign(n,vector<int>(n,0));

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        --u; --v;

        adj[u].push_back({v,1});
        adj[v].push_back({u,1});

        capacity[u][v] += 1;

        edges.push_back({u,v});
    }

    int flow=max_flow(0,n-1);

    cout<<flow<<"\n";

    vector<vector<int>> used(n);

    for(auto [u,v]:edges){
        if(capacity[u][v]==0)
            used[u].push_back(v);
    }

    for(int k=0;k<flow;k++){
        vector<int> path;

        int u=0;
        path.push_back(0);

        while(u!=n-1){
            int v=used[u].back();
            used[u].pop_back();

            path.push_back(v);
            u=v;
        }

        cout<<path.size()<<"\n";
        for(int x:path)
            cout<<x+1<<" ";
        cout<<"\n";
    }
}