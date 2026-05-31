// ::::::::: REVISE
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    while (q--) {
        ll k;
        cin >> k;

        ll len = 1;
        ll cnt = 9;

        while (k > cnt * len) {
            k -= cnt * len;
            len++;
            cnt *= 10;
        }

        ll start = 1;
        for (int i = 1; i < len; i++) start *= 10;

        ll num = start + (k - 1) / len;
        ll pos = (k - 1) % len;

        cout << to_string(num)[pos] << '\n';
    }
}