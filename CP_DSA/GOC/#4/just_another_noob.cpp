// https://www.hackerrank.com/contests/goc-cdc-series-4/challenges/just-another-noob/problem?isFullScreen=true
// ::::::: FT
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
#define endl '\n'

class FT {
public:
    ll n; vector<ll> bit;
    
    FT(ll s) {
        n = s;
        bit.assign(n+1, 0);
    }
    
    void update(ll idx, ll inc) {
        while(idx <= n) {
            bit[idx] += inc;
            idx += idx & -idx;
        }
    }
    
    ll query(ll idx) {
        ll res = 0;
        while(idx > 0) {
            res += bit[idx];
            idx -= idx & -idx;
        }
        return res;
    }
    
    ll range(ll a, ll b) {
        return query(b) - query(a-1);
    }
    
    ll kth(ll k) {
        ll l = 1, r = n;

        while(l < r) {
            ll mid = (l + r) / 2;

            if(query(mid) >= k)
                r = mid;
            else
                l = mid + 1;
        }

        return l;
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n; cin >> n;
    vector<ll> arr(n);
    FT bit(n);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
        bit.update(i+1, 1);
    }
    
    vector<ll> ans(n+1, 0);
    for(ll i = n-1; i >= 0; i--) {
        ll pos = bit.kth(arr[i]);
        ans[pos] = i+1;
        bit.update(pos, -1);
    }
    for(ll i = 1; i <= n; i++) cout << ans[i] << " "; cout << endl;
    
    return 0;
}
