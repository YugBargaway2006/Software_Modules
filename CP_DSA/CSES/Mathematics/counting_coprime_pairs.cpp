// :::::: NEED to remember how to run inclusion - exclusion
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int MAXA = 1e6 + 5;

int mu[MAXA];
int lp[MAXA];
vector<int> primes;

void mobiusSieve() {
    mu[1] = 1;

    for (int i = 2; i < MAXA; i++) {
        if (!lp[i]) {
            lp[i] = i;
            primes.push_back(i);
            mu[i] = -1;
        }

        for (int p : primes) {
            if (1LL * p * i >= MAXA) break;

            lp[p * i] = p;

            if (p == lp[i]) {
                mu[p * i] = 0;
                break;
            }

            mu[p * i] = -mu[i];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    mobiusSieve();

    int n;
    cin >> n;

    vector<int> freq(MAXA, 0);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        freq[x]++;
    }

    ll ans = 0;

    for (int d = 1; d < MAXA; d++) {
        ll cnt = 0;

        for (int j = d; j < MAXA; j += d)
            cnt += freq[j];

        ans += 1LL * mu[d] * (cnt * (cnt - 1) / 2);
    }

    cout << ans << endl;
}