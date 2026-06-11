// 12 : 15
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
ll n, q;
vector<ll> arr, id;

class ST {
public:
    ll n; vector<ll> tree;

    ST(ll s) {
        n = s;
        tree.assign(4*n, 0);
    }

    ll merge(ll a, ll b) {
        return (a + b);
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

    void queryupdate(ll node, ll l, ll r, ll idx) {
        if(l == r) {
            tree[node] -= 1;
            cout << arr[l] << " ";
            return;
        }
        ll mid = l + (r-l)/2;
        if(idx <= tree[2*node]) queryupdate(2*node, l, mid, idx);
        else queryupdate(2*node+1, mid+1, r, idx - tree[2*node]);

        tree[node] = merge(tree[2*node], tree[2*node+1]);
    } 
};


signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    arr.assign(n, 0);
    id.assign(n, 1);

    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    }   

    ST st(n);
    st.build(id, 1, 0, n-1);
    ll count = n;
    q = n;
    while(q--) {
        ll x; cin >> x;
        if(count < x) cout << " X ";
        else st.queryupdate(1, 0, n-1, x);
        count--;
    }
}