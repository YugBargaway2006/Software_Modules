// *** 12  : 44    :::::::  Code the Logic fast
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, q; cin >> n >> q;
    vector<ll> arr(n);
    vector<ll> idx(n+1);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
        idx[arr[i]] = i;
    }

    ll ct = 1;
    for(ll i = 1; i < n; i++) {
        if(idx[i] > idx[i+1]) {
            ct++;
        }
    }

    while(q--) {
        ll ia, ib; cin >> ia >> ib;
        ia--; ib--;

        ll a = arr[ia];
        ll b = arr[ib];

        vector<ll> aff = {a-1, a, a+1, b-1, b, b+1};
        vector<ll> oi = {idx[a-1], ia, idx[a+1], idx[b-1], ib, idx[b+1]};
        swap(arr[ia], arr[ib]);
        idx[a] = ib;
        idx[b] = ia;
        vector<ll> ni = {idx[a-1], ib, idx[a+1], idx[b-1], ia, idx[b+1]};

        // for(auto u : aff) cout << u << " ";
        // cout << endl;
        // for(auto u : oi) cout << u << " ";
        // cout << endl;
        // for(auto u : ni) cout << u << " ";
        // cout << endl;
        set<int> processed;

        for(ll i = 0; i < 5; i++) {
            if(i == 2) continue;
            if(aff[i] < 1 || aff[i] >= n) continue;
            if(processed.count(aff[i]) != 0) continue;
            processed.insert(aff[i]);
            // cout << aff[i] << " " << ct << " ";
            if(oi[i] > oi[i+1] && ni[i] < ni[i+1]) {
                ct--;
                // cout << ct << endl;
            }
            if(oi[i] < oi[i+1] && ni[i] > ni[i+1]) {
                ct++;
                // cout << ct << endl;
            }
        }
        // cout << endl;
        cout << ct<< endl;
    }

}

// 13 : 13