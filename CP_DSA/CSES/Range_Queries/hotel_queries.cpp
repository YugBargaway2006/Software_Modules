// 12 : 15
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

class ST {
public:
    ll n; vector<ll> tree;

    ST(ll s) {
        n = s;
        tree.assign(4*n, 0);
    }

    ll merge(ll a, ll b) {
        return max(a, b);
    }

    void build(vector<ll>& arr, ll node, ll l, ll r) {
        if(l == r) {
            tree[node] = arr[l];
            return;
        }
        ll mid = l + (r - l) /2;
        build(arr, 2*node, l, mid);
        build(arr, 2*node+1, mid+1, r);

        tree[node] = merge(tree[2*node], tree[2*node+1]);
    }

    void queryupdate(ll node, ll l, ll r, ll val) {
        if(l == r) {
            tree[node] -= val;
            cout << l+1 << " ";
            return;
        }
        ll mid = l + (r-l)/2;
        if(val <= tree[2*node]) queryupdate(2*node, l, mid, val);
        else queryupdate(2*node+1, mid+1, r, val);

        tree[node] = merge(tree[2*node], tree[2*node+1]);
    } 
};

ll n, q;
vector<ll> arr;

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    arr.assign(n, 0);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    }   

    ST st(n);
    st.build(arr, 1, 0, n-1);
    while(q--) {
        ll x; cin >> x;
        if(st.tree[1] < x) cout << 0 << " ";
        else st.queryupdate(1, 0, n-1, x);
    }
}