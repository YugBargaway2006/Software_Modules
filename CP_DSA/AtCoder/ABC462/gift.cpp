#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve() {

}

ll n;
vector<vector<ll>> adj;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    adj.assign(n, {});
    for(ll i= 0; i < n; i++) {
        ll k; cin >> k;
        for(ll j = 0; j < k; j++) {
            ll x; cin >> x;
            x--;
            adj[x].push_back(i);
        }
    }

    for(ll i = 0; i < n; i++) {
        cout << adj[i].size() << " ";
        for(auto x : adj[i]) cout << x+1 << " "; cout << endl;
    }
}