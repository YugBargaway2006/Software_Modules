#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct BIT {
    int n;
    vector<int> bit;

    BIT(int n) : n(n), bit(n + 1, 0) {}

    void add(int idx, int val) {
        for (; idx <= n; idx += idx & -idx)
            bit[idx] += val;
    }

    int sum(int idx) {
        int res = 0;
        for (; idx > 0; idx -= idx & -idx)
            res += bit[idx];
        return res;
    }

    int query(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};

struct Event {
    ll val;
    int l, r;
    int id;
    int sign;

    bool operator<(const Event& other) const {
        return val < other.val;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<pair<ll,int>> a; // {value, index}
    a.reserve(n);

    for (int i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        a.push_back({x, i});
    }

    sort(a.begin(), a.end());

    vector<Event> events;
    events.reserve(2 * q);

    for (int i = 0; i < q; i++) {
        int l, r;
        ll c, d;

        cin >> l >> r >> c >> d;

        events.push_back({d, l, r, i, +1});
        events.push_back({c - 1, l, r, i, -1});
    }

    sort(events.begin(), events.end());

    BIT bit(n);
    vector<ll> ans(q, 0);

    int ptr = 0;

    for (auto &e : events) {
        while (ptr < n && a[ptr].first <= e.val) {
            bit.add(a[ptr].second, 1);
            ptr++;
        }

        ans[e.id] += 1LL * e.sign * bit.query(e.l, e.r);
    }

    for (int i = 0; i < q; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}