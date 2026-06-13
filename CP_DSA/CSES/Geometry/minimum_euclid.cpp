#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

struct Point {
    ll x, y;
};

ll dist(Point a, Point b) {
    ll dx = a.x - b.x;
    ll dy = a.y - b.y;
    return dx * dx + dy * dy;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;

    vector<Point> p(n);

    for(ll i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
    }

    sort(p.begin(), p.end(), [](Point a, Point b) {
        return a.x < b.x;
    });

    ll ans = dist(p[0], p[1]);

    set<pair<ll,ll>> active; // {y,x}

    active.insert({p[0].y, p[0].x});

    ll left = 0;

    for(ll i = 1; i < n; i++) {

        ll d = ceil(sqrt((long double)ans));

        while(left < i &&
              p[i].x - p[left].x > d) {

            active.erase({p[left].y, p[left].x});
            left++;
        }

        auto it1 = active.lower_bound({
            p[i].y - d,
            -(ll)4e18
        });

        auto it2 = active.upper_bound({
            p[i].y + d,
            (ll)4e18
        });

        for(auto it = it1; it != it2; it++) {

            Point q = {
                it->second,
                it->first
            };

            ans = min(ans, dist(p[i], q));
        }

        active.insert({
            p[i].y,
            p[i].x
        });
    }

    cout << ans << endl;
}