#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct Event {
    int x;
    int type; // 0 = add, 1 = query, 2 = remove

    int y;
    int y1, y2;

    bool operator<(const Event& other) const {
        if(x != other.x) return x < other.x;
        return type < other.type;
    }
};

struct Fenwick {
    int n;
    vector<int> bit;

    Fenwick(int n) : n(n), bit(n + 1, 0) {}

    void add(int idx, int val) {
        for(; idx <= n; idx += idx & -idx)
            bit[idx] += val;
    }

    int sum(int idx) {
        int res = 0;
        for(; idx > 0; idx -= idx & -idx)
            res += bit[idx];
        return res;
    }

    int query(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Event> events;
    vector<int> ys;

    for(int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        if(y1 == y2) {
            // horizontal
            events.push_back({x1, 0, y1, 0, 0});
            events.push_back({x2, 2, y1, 0, 0});

            ys.push_back(y1);
        }
        else {
            // vertical
            events.push_back({x1, 1, 0, y1, y2});

            ys.push_back(y1);
            ys.push_back(y2);
        }
    }

    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());

    auto getY = [&](int y) {
        return lower_bound(ys.begin(), ys.end(), y) - ys.begin() + 1;
    };

    for(auto &e : events) {
        if(e.type == 0 || e.type == 2) {
            e.y = getY(e.y);
        } else {
            e.y1 = getY(e.y1);
            e.y2 = getY(e.y2);
        }
    }

    sort(events.begin(), events.end());

    Fenwick ft((int)ys.size());

    long long ans = 0;

    for(auto &e : events) {
        if(e.type == 0) {
            ft.add(e.y, 1);
        }
        else if(e.type == 2) {
            ft.add(e.y, -1);
        }
        else {
            ans += ft.query(e.y1, e.y2);
        }
    }

    cout << ans << '\n';
}