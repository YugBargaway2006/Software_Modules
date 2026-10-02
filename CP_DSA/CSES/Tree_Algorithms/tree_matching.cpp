#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj1;
vector<vector<int>> adj2;

vector<int> findCenters(vector<vector<int>>& adj, int n) {
    vector<int> degree(n+1);
    queue<int> q;

    for(int i = 1; i <= n; i++) {
        degree[i] = adj[i].size();
        if(degree[i] == 1) q.push(i);
    }

    int remaining = n;

    while(remaining > 2) {
        int sz = q.size();
        remaining -= sz;

        while(sz--) {
            int u = q.front(); q.pop();

            for(int v : adj[u]) {
                degree[v]--;
                if(degree[v] == 1) q.push(v);
            }
        }
    }

    vector<int> centers;
    while(!q.empty()) {
        centers.push_back(q.front());
        q.pop();
    }

    return centers;
}

string hashtree(vector<vector<int>>& adj, int s, int parent) {
    vector<string> children;

    for(auto v : adj[s]) {
        if(v != parent) {
            children.push_back(hashtree(adj, v, s));
        }
    }

    sort(children.begin(), children.end());

    string ans = "(";
    for(auto &c : children) ans += c;
    ans += ")";

    return ans;
}


int main(void) {
    int n; cin >> n;
    adj1.assign(n+1, {});
    adj2.assign(n+1, {});
    
    map<int, int> mp1, mp2;
    int id1 = 1, id2 = 1;
    
    auto get1 = [&](int x) {
        if(mp1.count(x)) return mp1[x];
        return mp1[x] = id1++;
    };
    
    auto get2 = [&](int x) {
        if(mp2.count(x)) return mp2[x];
        return mp2[x] = id2++;
    };
    
    for(int i = 0; i < n-1; i++) {
        int x, y; cin >> x >> y;
        x = get1(x);
        y = get1(y);
        adj1[x].push_back(y);
        adj1[y].push_back(x);
    }

    for(int i = 0; i < n-1; i++) {
        int x, y; cin >> x >> y;
        x = get2(x);
        y = get2(y);
        adj2[x].push_back(y);
        adj2[y].push_back(x);
    }

    auto centers1 = findCenters(adj1, n);
    auto centers2 = findCenters(adj2, n);

    for(int c1 : centers1) {
        string h1 = hashtree(adj1, c1, -1);

        for(int c2 : centers2) {
            string h2 = hashtree(adj2, c2, -1);

            if(h1 == h2) {
                cout << "YES\n";
                return 0;
            }
        }
    }

    cout << "NO\n";
}