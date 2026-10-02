#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

long long modpow(long long a, long long e) {
    long long r = 1;
    while (e) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k, x, y;
    cin >> k >> x >> y;

    if (k < max(x, y) || k > x + y) {
        cout << 0 << '\n';
        return 0;
    }

    int n = x + y;

    vector<long long> fac(n + 1), invfac(n + 1);
    fac[0] = 1;
    for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % MOD;

    invfac[n] = modpow(fac[n], MOD - 2);
    for (int i = n; i >= 1; i--)
        invfac[i - 1] = invfac[i] * i % MOD;

    auto C = [&](int N, int R) -> long long {
        if (R < 0 || R > N) return 0;
        return fac[N] * invfac[R] % MOD * invfac[N - R] % MOD;
    };

    auto F = [&](int M) -> long long {
        if (M < max(0, x - y)) return 0;
        long long ans = (C(n, y) - C(n, y + M + 1)) % MOD;
        if (ans < 0) ans += MOD;
        return ans;
    };

    int M = k - y;

    long long ans;
    if (k > x) {
        ans = (F(M) - F(M - 1)) % MOD;
        if (ans < 0) ans += MOD;
    } else {
        ans = F(M);
    }

    cout << ans % MOD << '\n';
}