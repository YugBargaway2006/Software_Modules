// Write your code here
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll mxv = 1e15;
    vector<ll> ugly, nxt;
    ugly.push_back(1);
    ll v = 1;
    nxt = ugly;
    for(ll i = 0; i < 32; i++) {
        v *= 2;
        if(v > mxv) continue;
        for(auto e : ugly) {
            if(e*v > mxv) break;
            nxt.push_back(e*v);
        }
    }
    ugly = nxt;

    sort(ugly.begin(), ugly.end());
    nxt = ugly;
    v = 1;
    for(ll i = 0; i < 32; i++) {
        v *= 3;
        if(v > mxv) continue;
        for(auto e : ugly) {
            if(e*v > mxv) break;
            nxt.push_back(e*v);
        }
    }
    ugly = nxt;

    sort(ugly.begin(), ugly.end());
    nxt = ugly;
    v = 1;
    for(ll i = 0; i < 32; i++) {
        v *= 5;
        if(v > mxv) continue;
        for(auto e : ugly) {
            if(e*v > mxv) break;
            nxt.push_back(e*v);
        }
    }
    ugly = nxt;

    sort(ugly.begin(), ugly.end());
    // for(auto x : ugly) cout << x << " "; cout << endl;
    ll t; cin >> t;
    while(t--) {
        ll n; cin >> n; n--;
        cout << ugly[n] << endl;
    }
}