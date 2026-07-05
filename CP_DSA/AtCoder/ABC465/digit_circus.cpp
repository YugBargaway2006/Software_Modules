#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define endl '\n'

ll mod = 998244353;
int memo[505][3][2][1024];
string s;

ll dp(ll idx, bool tight, ll mod3, bool h3, ll mask) {
    if(idx == s.size()) {
        if(mask == 0) {
            return 0;
        }

        bool c1 = (mod3 == 0);
        bool c2 = h3;
        bool c3 = (__builtin_popcount(mask) == 3);
        ll condition = c1+c2+c3;
        return condition == 1 ? 1 : 0;
    }

    if(!tight && memo[idx][mod3][h3][mask] != -1) {
        return memo[idx][mod3][h3][mask];
    }

    ll limit = (tight) ? s[idx] - '0' : 9;
    ll ans = 0;

    for(ll d = 0; d <= limit; d++) {
        bool nt = (tight) && (d == limit);
        ll nm = mask;
        if(mask > 0 || d > 0) {
            nm |= (1 << d);
        }
        
        ll nm3 = (mod3+d)%3;
        bool nh3 = h3 || (d == 3);

        ans = (ans + dp(idx+1, nt, nm3, nh3, nm)) % mod;
    }

    if(!tight) {
        memo[idx][mod3][h3][mask] = ans;
    }

    return ans;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;

    memset(memo, -1, sizeof(memo));

    cout << dp(0, true, 0, false, 0) << endl;

}

