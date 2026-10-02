#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define endl '\n'

ll mod = 1e9+7;
ll mi2 = 0;

ll power(ll b, ll p, ll mod = mod) {
    ll res = 1;
    b = b % mod;
    while(p > 0) {
        if(p%2 == 1) {
            res = (res * b) % mod;
        }
        b = (b*b) % mod;
        p /= 2;
    }
    return res;
}

ll modi(ll b) {
    return power(b, mod-2);
}

void solve() {
    ll n; 
    cin >> n;
    string s; 
    cin >> s;

    mi2 = modi(2); 

    ll E0 = 0; 
    ll E1 = 1; 

    for(int i = 1; i < n; i++) {
        ll next_E0, next_E1;
        
        ll odd_calculation = (1 + (E0 * mi2) % mod + (E1 * mi2) % mod) % mod;

        if(s[i] == '0') {
            next_E0 = (1 + E0) % mod;
            next_E1 = odd_calculation;
        } else {
            next_E0 = odd_calculation;
            next_E1 = (1 + E1) % mod;
        }
        
        E0 = next_E0;
        E1 = next_E1;
    }

    cout << E0 << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t; cin >> t;
    while(t--) {
        solve();
    }
}