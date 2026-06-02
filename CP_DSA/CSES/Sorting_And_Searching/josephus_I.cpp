// 18 : 12
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

signed main(void) {
    ll n; cin >> n;
    queue<ll> q;
    for(ll i = 1; i <= n; i++) q.push(i);
    int c = 0;
    while(!q.empty()) {
        c++;
        int u = q.front(); q.pop();
        if(c%2 == 0) cout << u << " ";
        else q.push(u);
    }
    cout << endl;
}