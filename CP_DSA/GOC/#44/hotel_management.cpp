#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    vector<ll> checkin(n), checkout(n);
    vector<pair<ll, ll>> events;

    for (ll i = 0; i < n; i++)
        cin >> checkin[i];

    for (ll i = 0; i < n; i++) {
        cin >> checkout[i];
        events.push_back({checkin[i], +1});
        events.push_back({checkout[i] + 1, -1});
    }

    sort(events.begin(), events.end());

    vector<pair<ll, ll>> seg;   // {occupancy, length}

    ll cur = 0;
    int i = 0;
    int m = events.size();

    while (i < m) {
        ll day = events[i].first;

        while (i < m && events[i].first == day) {
            cur += events[i].second;
            i++;
        }

        if (i == m) break;

        ll nextDay = events[i].first;
        ll len = nextDay - day;

        if (len > 0)
            seg.push_back({cur, len});
    }

    ll mx = 0;
    for (auto &x : seg)
        mx = max(mx, x.first);

    ll ans = 0;
    for (auto &x : seg)
        if (x.first == mx)
            ans += x.second;

    cout << ans << '\n';

    return 0;
}
