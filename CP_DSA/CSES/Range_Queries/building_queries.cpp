// 18 : 04   ::::: NEED DEPTH REVISION
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ll n, q;
vector<ll> arr, nextg, depth;
ll mx = 30;
vector<vector<ll>> bj;

void nextlarger() {
    stack<ll> s;
    s.push(n-1);
    depth[n-1] = 1;
    for(ll i = n-2; i >= 0; i--) {
        while(!s.empty() && arr[s.top()] <= arr[i]) {
            s.pop();
        }
        if(s.empty()) {
            nextg[i] = n;
            depth[i] = 1;
        }
        else {
            nextg[i] = s.top();
            depth[i] = depth[s.top()]+1;
        }
        s.push(i);
    }
}

ll step(ll a, ll b) {    // Main logic to remember
    ll cnt = 1;
    if(a == b) return 1;
    for(ll j = mx-1; j >= 0; j--) {
        if(bj[a][j] <= b) {
            cnt += (1LL << j);
            a = bj[a][j];
        }
    }
    return cnt;
}

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    arr.assign(n, 0);
    nextg.assign(n, n);
    depth.assign(n, 0);
    nextg[n-1] = n;
    depth[n-1] = 1;
    bj.assign(n+1, vector<ll>(mx, n));
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    nextlarger();

    for(ll i = 0; i < n; i++) {
        bj[i][0] = nextg[i];
    }
    for(ll j = 1; j < mx; j++) {
        for(ll i = 0; i < n; i++) {
            bj[i][j] = (bj[i][j-1] == n) ? n : bj[bj[i][j-1]][j-1];
        }
    }

    while(q--) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        cout << step(a, b) << endl;
    }
}