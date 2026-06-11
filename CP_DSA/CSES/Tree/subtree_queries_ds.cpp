// 16 : 37
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

typedef struct TreeNode {
    ll idx;
    ll data;
    ll subtree = 0;
    vector<TreeNode*> child;
    TreeNode* parent;
    
};

ll n, q; 
vector<vector<ll>> adj;
vector<TreeNode*> mapping;
vector<ll> idata;

TreeNode* dfs(ll u, TreeNode* p) {
    TreeNode* newnode = new TreeNode();
    newnode->idx = u;
    newnode->data = idata[u];
    newnode->parent = p;
    newnode->subtree = idata[u];

    for(auto v : adj[u]) {
        if(p != nullptr && v == p->idx) continue;
        TreeNode* childnode = dfs(v, newnode);
        newnode->child.push_back(childnode);
        newnode->subtree += childnode->subtree;
    }
    mapping[u] = newnode;
    return newnode;
}



signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    idata.assign(n, 0);
    for(ll i = 0; i < n; i++) cin >> idata[i];
    mapping.resize(n);
    adj.assign(n, {});
    for(ll i = 0; i < n-1; i++) {
        ll x, y; cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    TreeNode* root = dfs(0, nullptr);
    while(q--) {
        ll x; cin >> x;
        if(x == 1) {
            ll s, v; cin >> s >> v; s--;
            ll diff = v - mapping[s]->data;
            mapping[s]->data = v;
            TreeNode* curr = mapping[s];
            while(curr != nullptr) {
                curr->subtree += diff;
                curr = curr -> parent;
            }
        } else {
            ll s; cin >> s; s--;
            cout << mapping[s]->subtree << endl;
        }
    }

}