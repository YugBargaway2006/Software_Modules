#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define endl '\n'

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, m; cin >> n >> m;
    vector<vector<pair<bool, ll>>> arr(m+1);
    for(ll i = 0; i < n; i++) {
        ll a, d, b; cin >> a >> d >> b;
        arr[1].push_back({true, a});
        arr[d].push_back({false, a});
        arr[d].push_back({true, b});
    }

    map<ll, ll> ct;
    ll ans = 0;
    for(ll i = 1; i <= m; i++) {
        for(auto [coming, idx] : arr[i]) {
            if(!coming) {
                ct[idx] -= 1;
                if(ct[idx] == 0) {
                    ct.erase(idx);
                    ans--;
                }
            } else {
                ct[idx] += 1;
                if(ct[idx] == 1) {
                    ans++;
                }
            }
        }
        cout << ans << endl;    
    }
}