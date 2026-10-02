#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define endl '\n'

map<char, ll> freq;

ll cal(ll len) {
    ll m1 = 0, m2 = 0;

    for (auto p : freq) {
        ll f = p.second;
        if (f >= m1) {
            m2 = m1;
            m1 = f;
        } else if (f > m2) {
            m2 = f;
        }
    }

    return len - m1 - m2;
}

void solve() {
    freq.clear();
    string s; cin >> s;
    ll k; cin >> k;

    ll n = s.size();

    ll l = 0, r = 0;
    ll ans = 0;
    while(r < n) {
        freq[s[r]]++;
        ll len = r-l+1;
        while(l <= r && cal(r-l+1) > k) {
            freq[s[l]]--;
            l++;
        }

        // cout << cal(r-l+1) << endl;
        if(cal(r-l+1) <= k) {
            // cout << l << " " << r << " " << ans << endl;
            ans = max(ans, r-l+1);
        }
        r++;
    }
    cout << ans << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t; cin >> t;
    // cout << endl;
    while(t--) {
        solve();
    }
}

