#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

vector<ll> dp(1e6+1, 0);
vector<pair<ll, ll>> arr;
ll n;
ll mxn = 1e6;

void filldp() {
    for(auto [num, v] : arr) {
        dp[num] += v;
    }

    ll p10 = 1;
    for(ll d = 0; d < 6; d++) {
        for(ll i = 0; i < mxn; i++) {
            ll cd = (i / p10) % 10;
            if(cd > 0) {
                dp[i] += dp[i-p10];
            }
        }
        p10 *= 10;
    }
}

void query() {
    string x, y; 
    cin >> x >> y;

    ll total = 0;
    
    ll p10[6] = {100000, 10000, 1000, 100, 10, 1};

    for(ll mask = 0; mask < 64; mask++) {
        ll current_index = 0;
        bool out_of_bounds = false;
        
        for (int k = 0; k < 6; k++) {
            int digit;
            
            if ((mask >> (5 - k)) & 1) {
                digit = (x[k] - '0') - 1; // Excluded lower bound
            } else {
                digit = (y[k] - '0');     // Upper bound
            }
            
            if (digit < 0) {
                out_of_bounds = true;
                break;
            }
            
            current_index += digit * p10[k];
        }
        
        if (out_of_bounds) continue;
        
        if (__builtin_popcount(mask) % 2 == 1) {
            total -= dp[current_index];
        } else {
            total += dp[current_index];
        }
    }
    
    if(total < 0) cout << 0 << endl;
    else cout << total << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    arr.assign(n, {});
    for(ll i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    filldp();

    ll q; cin >> q;
    while(q--) {
        query();
    }

    return 0;
}