#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll mod = 1e9+7;
const ll base = 911382323;

vector<ll> pw;

struct Node {
    ll hash = 0;
    ll len = 0;
};

class ST {
public:
    ll n;
    vector<Node> tree;

    ST(ll s) {
        n = s;
        tree.resize(4*n);
    }

    Node merge(Node a, Node b) {
        return {
            ((a.hash * pw[b.len]) % mod + b.hash) % mod,
            a.len + b.len
        };
    }

    void build(vector<ll>& arr, ll node, ll l, ll r) {
        if(l == r) {
            tree[node] = {arr[l], 1};
            return;
        }

        ll mid = (l+r)/2;
        build(arr, 2*node, l, mid);
        build(arr, 2*node+1, mid+1, r);

        tree[node] = merge(tree[2*node], tree[2*node+1]);
    }

    void update(ll node, ll l, ll r, ll idx, ll val) {
        if(l == r) {
            tree[node] = {val, 1};
            return;
        }

        ll mid = (l+r)/2;

        if(idx <= mid)
            update(2*node, l, mid, idx, val);
        else
            update(2*node+1, mid+1, r, idx, val);

        tree[node] = merge(tree[2*node], tree[2*node+1]);
    }

    Node query(ll node, ll l, ll r, ll ql, ll qr) {
        if(qr < l || r < ql)
            return {0, 0};

        if(ql <= l && r <= qr)
            return tree[node];

        ll mid = (l+r)/2;

        return merge(
            query(2*node, l, mid, ql, qr),
            query(2*node+1, mid+1, r, ql, qr)
        );
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    pw.resize(n+1);
    pw[0] = 1;
    for(int i=1;i<=n;i++)
        pw[i] = pw[i-1] * base % mod;

    vector<ll> arr(n);
    for(int i=0;i<n;i++)
        arr[i] = s[i];

    vector<ll> rev = arr;
    reverse(rev.begin(), rev.end());

    ST fwd(n), bwd(n);

    fwd.build(arr, 1, 0, n-1);
    bwd.build(rev, 1, 0, n-1);

    while(q--) {
        int t;
        cin >> t;

        if(t == 1) {
            int k;
            char x;
            cin >> k >> x;
            k--;

            fwd.update(1, 0, n-1, k, x);
            bwd.update(1, 0, n-1, n-1-k, x);
        }
        else {
            int a, b;
            cin >> a >> b;
            a--; b--;

            Node x = fwd.query(1, 0, n-1, a, b);
            Node y = bwd.query(1, 0, n-1, n-1-b, n-1-a);

            cout << (x.hash == y.hash ? "YES\n" : "NO\n");
        }
    }
}