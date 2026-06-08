// 13 : 19
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

ll d = 30;
ll n, q;
vector<vector<ll>> adj;
vector<vector<ll>> bin;

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    bin.assign(n, vector<ll>(d, -1));
    adj.assign(n, {});
    for(ll i = 1; i < n; i++) {
        ll x; cin >> x; x--;
        adj[x].push_back(i);
        bin[i][0] = x;
    }

    for(ll i = 1; i < d; i++) {
        for(ll j = 0; j < n; j++) {
            bin[j][i] = (bin[j][i-1] == -1) ? -1 : bin[bin[j][i-1]][i-1];
        }
    }

    // for(ll i = 0; i < 2; i++) {
    //     for(ll j = 0; j < n; j++) {
    //         cout << j << " -> " << bin[j][i] << " ";
    //     }
    //     cout << endl;
    // }

    while(q--) {
        ll x, k; cin >> x >> k;
        x--;
        ll ans = x;

        for(ll i  = 0; i < d; i++ ) {
            if((k & (1 << i)) != 0) {
                // cout << ans << " " << i << endl;
                if(ans == -1) break;
                ans = bin[ans][i];
            }
        }
        (ans == -1) ? cout << -1 << endl : cout << ans+1 << endl;
    }
}