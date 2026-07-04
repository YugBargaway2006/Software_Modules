// https://www.hackerrank.com/contests/goc-cdc-series-4/challenges/good-subarrays-1/problem?isFullScreen=true
// ::: Remember I didnt write it, so need to understand carefully
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> A(N + 1);
    for (int i = 1; i <= N; i++) cin >> A[i];

    const int MAXA = 1000000;

    // SPF sieve
    vector<int> spf(MAXA + 1);
    for (int i = 0; i <= MAXA; i++) spf[i] = i;

    for (int i = 2; i * i <= MAXA; i++) {
        if (spf[i] == i) {
            for (long long j = 1LL * i * i; j <= MAXA; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }

    const int INF = 1e9;

    vector<int> best(MAXA + 1, INF);
    vector<int> dp(N + 1, INF);

    dp[0] = 0;

    for (int i = 1; i <= N; i++) {
        vector<int> primes;

        int x = A[i];
        while (x > 1) {
            int p = spf[x];
            primes.push_back(p);
            while (x % p == 0) x /= p;
        }

        int mn = dp[i - 1]; // single-element segment

        for (int p : primes) {
            mn = min(mn, best[p]);
        }

        dp[i] = mn + 1;

        for (int p : primes) {
            best[p] = min(best[p], dp[i - 1]);
        }
    }

    cout << dp[N] << '\n';
    return 0;
}