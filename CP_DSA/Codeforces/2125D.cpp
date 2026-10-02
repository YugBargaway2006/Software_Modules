#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define endl '\n'

const ll MOD = 998244353;

ll power(ll base, ll exp) {
    ll result = 1;
    base = base % MOD;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    return result;
}

ll modInverse(ll n) {
    return power(n, MOD - 2);
}

struct Segment {
    ll l, r;
    ll weight;
    
    bool operator<(const Segment& other) const {
        if (r != other.r)
            return r < other.r;
        return l < other.l;
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;

    ll P_none = 1;
    vector<Segment> segments;
    segments.reserve(n);

    for (ll i = 0; i < n; ++i) {
        ll l, r;
        ll p, q;
        cin >> l >> r >> p >> q;

        ll P = (p * modInverse(q)) % MOD;
        
        ll invP = (1 - P + MOD) % MOD;

        P_none = (P_none * invP) % MOD;

        ll weight = (P * modInverse(invP)) % MOD;

        segments.push_back({l, r, weight});
    }

    sort(segments.begin(), segments.end());

    vector<long long> dp(m + 1, 0);
    dp[0] = 1; 

    for (const auto& seg : segments) {
        int l = seg.l;
        int r = seg.r;
        ll w = seg.weight;

        dp[r] = (dp[r] + dp[l - 1] * w) % MOD;
    }

    ll final_probability = (dp[m] * P_none) % MOD;
    cout << final_probability << "\n";
}