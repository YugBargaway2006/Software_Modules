#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
#define endl '\n'

void solve() {
    string s;
    cin >> s;

    int n = (int)s.size();

    vector<int> odd(n), even(n);

    // Manacher odd
    for (int l = 0, r = -1, i = 0; i < n; i++) {
        int k = (i > r) ? 1 : min(odd[l + r - i], r - i + 1);
        while (i - k >= 0 && i + k < n &&
                s[i - k] == s[i + k]) {
            k++;
        }
        odd[i] = k;
        k--;

        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
    }

    // Manacher even
    for (int l = 0, r = -1, i = 0; i < n; i++) {
        int k = (i > r) ? 0 : min(even[l + r - i + 1], r - i + 1);

        while (i - k - 1 >= 0 && i + k < n &&
                s[i - k - 1] == s[i + k]) {
            k++;
        }

        even[i] = k;
        k--;

        if (i + k > r) {
            l = i - k - 1;
            r = i + k;
        }
    }

    vector<int> endExact(n, 0), startExact(n, 0);

    // Odd palindromes
    for (int c = 0; c < n; c++) {
        for (int k = 1; k <= odd[c]; k++) {
            int l = c - k + 1;
            int r = c + k - 1;
            int len = 2 * k - 1;

            endExact[r] = max(endExact[r], len);
            startExact[l] = max(startExact[l], len);
        }
    }

    // Even palindromes
    for (int c = 0; c < n; c++) {
        for (int k = 1; k <= even[c]; k++) {
            int l = c - k;
            int r = c + k - 1;
            int len = 2 * k;

            endExact[r] = max(endExact[r], len);
            startExact[l] = max(startExact[l], len);
        }
    }

    vector<ll> pref(n), suff(n);

    pref[0] = endExact[0];
    for (int i = 1; i < n; i++) {
        pref[i] = max(pref[i - 1], (ll)endExact[i]);
    }

    suff[n - 1] = startExact[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        suff[i] = max(suff[i + 1], (ll)startExact[i]);
    }

    ll ans = 0;

    for (int i = 0; i + 1 < n; i++) {
        ans = max(ans, pref[i] * suff[i + 1]);
    }

    cout << ans << '\n';
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll t; cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
