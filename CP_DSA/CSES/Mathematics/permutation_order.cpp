// 15 : 50
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

vector<ll> fact(21, 1);

void query1() {
    ll n, k; cin >> n >> k;
    set<ll> used;
    vector<ll> order(n);
    for(ll i = 0; i < n; i++) order[i] = i+1;
    k--;
    
    for(ll pos = n; pos >= 1; pos--) {
        ll block = fact[pos-1];
        ll idx = k / block;
        cout << order[idx] << " ";
        order.erase(order.begin() + idx);
        k %= block;
    }
    cout << endl;
}

void query2() {
    ll n; cin >> n;
    vector<ll> perm(n);
    for(ll i = 0; i < n; i++) {
        cin >> perm[i];
    }

    vector<ll> order(n);
    for(ll i = 0; i < n; i++) order[i] = i+1;

    ll rank = 0;
    for(ll i = 0; i < n; i++) {
        ll idx = 0;
        while(order[idx] != perm[i]) idx++;
        rank += idx * fact[n-i-1];
        order.erase(order.begin() + idx);
    }
    cout << rank + 1 << endl;
}

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(ll i = 2; i < 21; i++) {
        fact[i] = i * fact[i-1];
    }

    ll t; cin >> t;
    while(t--) {
        ll x; cin >> x;
        if(x == 1) query1();
        else query2();
    }
}
