#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define endl '\n'

void solve() {
    ll n, m; cin >> n >> m;
    vector<vector<ll>> color(n, vector<ll>(n, 1));

    for(ll i = 0; i < m; i++) {
        ll u, v; cin >> u >> v; u--; v--;
        
        color[u][v] = 0;
        color[v][u] = 0;
    }

    vector<ll> state(n, -1);
    ll ops = 0;

    for(ll i = 0; i < n; i++) {
        if(state[i] != -1) continue;

        queue<ll> q;
        q.push(i);
        state[i] = 0;

        ll c0 = 0, c1 = 0;

        while(!q.empty()) {
            ll curr = q.front();
            q.pop();

            if(state[curr] == 0) c0++;
            else c1++;

            for(ll nxt = 0; nxt < n; nxt++) {
                if(curr == nxt) continue;
                ll req = (color[curr][nxt] == 0) ? state[curr] : (1 - state[curr]);

                if(state[nxt] == -1) {
                    state[nxt] = req;
                    q.push(nxt);
                } else if(state[nxt] != req) {
                    cout << -1 << endl;
                    return;
                }
            }
        }
        ops += min(c0, c1);
    }
    
    cout << ops << endl;

}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t; cin >> t; 
    while(t--) {
        solve();
    }
}