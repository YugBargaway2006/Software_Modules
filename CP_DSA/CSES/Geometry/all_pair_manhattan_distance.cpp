#include <bits/stdc++.h>
using namespace std;

#define ll long long

using i128 = __int128_t;

i128 calc(vector<ll>& a) {
    sort(a.begin(), a.end());

    i128 pref = 0;
    i128 ans = 0;

    for(ll i = 0; i < (ll)a.size(); i++) {
        ans += (i128)i * a[i] - pref;
        pref += a[i];
    }

    return ans;
}

void print128(i128 x) {
    if(x == 0) {
        cout << 0;
        return;
    }

    string s;

    while(x > 0) {
        s.push_back('0' + (x % 10));
        x /= 10;
    }

    reverse(s.begin(), s.end());
    cout << s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    vector<ll> x(n), y(n);

    for(ll i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    i128 ans = calc(x) + calc(y);

    print128(ans);
    cout << '\n';

    return 0;
}