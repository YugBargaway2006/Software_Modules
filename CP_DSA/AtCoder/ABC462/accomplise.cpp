#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    ll D;
    cin >> N >> D;

    const int MX = 1000000;

    vector<ll> diff(MX + 3, 0);

    for (int i = 0; i < N; i++) {
        ll S, T;
        cin >> S >> T;

        ll L = S;
        ll R = T - D;

        if (L > R) continue;

        diff[L]++;
        diff[R + 1]--;
    }

    ll cur = 0;
    long long ans = 0;

    for (int t = 1; t <= MX; t++) {
        cur += diff[t];
        ans += cur * (cur - 1) / 2;
    }

    cout << ans << '\n';
}