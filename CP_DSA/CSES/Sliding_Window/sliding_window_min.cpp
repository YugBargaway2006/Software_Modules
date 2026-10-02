// 22 : 52
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ll n, k;
ll x, a, b, c; 

ll next(ll x) {
    return (a*x + b) % c;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    cin >> x >> a >> b >> c;

    deque<pair<ll, ll>> dq; // {value, index}
    ll ans = 0;

    for (ll i = 1; i <= n; i++) {
        while (!dq.empty() && dq.back().first >= x)
            dq.pop_back();

        dq.push_back({x, i});

        while (!dq.empty() && dq.front().second <= i - k)
            dq.pop_front();

        if (i >= k)
            ans ^= dq.front().first;

        x = next(x);
    }
    cout << ans << endl;
}