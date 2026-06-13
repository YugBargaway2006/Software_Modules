#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;

    vector<pair<ll,ll>> p(n);

    for(ll i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
    }

    ll area2 = 0;
    ll boundary = 0;

    for(ll i = 0; i < n; i++) {
        auto [x1,y1] = p[i];
        auto [x2,y2] = p[(i+1)%n];

        area2 += x1*y2 - y1*x2;

        boundary += gcd(
            abs(x2-x1),
            abs(y2-y1)
        );
    }

    area2 = abs(area2);

    ll interior = (area2 - boundary + 2) / 2;

    cout << interior << " " << boundary << endl;
}