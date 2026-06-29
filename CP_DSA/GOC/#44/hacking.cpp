#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
#define endl '\n'

bool check(ll a, ll b) {
    return (a & b) >= (a ^ b);
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> arr(n);

    for (ll i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());

    ll ct = 0;

    for (ll i = 0; i < n; i++) {
        ll l = i, r = n - 1;
        ll last = i - 1;

        while (l <= r) {
            ll mid = l + (r - l) / 2;

            if (check(arr[i], arr[mid])) {
                last = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        ct += (last - i);
    }

    cout << ct << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while (t--)
        solve();
}
