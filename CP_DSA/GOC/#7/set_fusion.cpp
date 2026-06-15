// https://www.hackerrank.com/contests/goc-cdc-series-7/challenges/sets-fusion/problem?isFullScreen=true

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define gcd __gcd

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        ll n, m, K1, K2;
        cin >> n >> m >> K1 >> K2;

        vector<ll> A(n), B(m);

        for (ll i = 0; i < n; i++) cin >> A[i];
        for (ll i = 0; i < m; i++) cin >> B[i];

        ll ga = 0, gb = 0;

        for (ll i = 1; i < n; i++)
            ga = gcd(ga, llabs(A[i] - A[0]));

        for (ll i = 1; i < m; i++)
            gb = gcd(gb, llabs(B[i] - B[0]));

        ll ans = gcd(K1 * A[0] + K2 * B[0],
                     gcd(K1 * ga, K2 * gb));

        cout << ans << '\n';
    }

    return 0;
}