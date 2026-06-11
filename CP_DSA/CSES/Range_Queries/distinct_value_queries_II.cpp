// Very Very Difficult 
#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct SegTree {
    int n;
    vector<int> st;

    SegTree(int n) : n(n), st(4 * n + 4, 0) {}

    void build(int p, int l, int r, const vector<int>& prev) {
        if (l == r) {
            st[p] = prev[l];
            return;
        }

        int m = (l + r) >> 1;
        build(p << 1, l, m, prev);
        build(p << 1 | 1, m + 1, r, prev);

        st[p] = max(st[p << 1], st[p << 1 | 1]);
    }

    void update(int p, int l, int r, int idx, int val) {
        if (l == r) {
            st[p] = val;
            return;
        }

        int m = (l + r) >> 1;

        if (idx <= m)
            update(p << 1, l, m, idx, val);
        else
            update(p << 1 | 1, m + 1, r, idx, val);

        st[p] = max(st[p << 1], st[p << 1 | 1]);
    }

    int query(int p, int l, int r, int ql, int qr) {
        if (r < ql || qr < l) return 0;

        if (ql <= l && r <= qr) return st[p];

        int m = (l + r) >> 1;

        return max(
            query(p << 1, l, m, ql, qr),
            query(p << 1 | 1, m + 1, r, ql, qr)
        );
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> a(n + 1);
    vector<int> prev(n + 1, 0);

    unordered_map<int, set<int>> pos;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]].insert(i);
    }

    for (auto &kv : pos) {
        int last = 0;
        for (int p : kv.second) {
            prev[p] = last;
            last = p;
        }
    }

    SegTree seg(n);
    seg.build(1, 1, n, prev);

    auto set_prev = [&](int idx, int val) {
        prev[idx] = val;
        seg.update(1, 1, n, idx, val);
    };

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int k, u;
            cin >> k >> u;

            if (a[k] == u) continue;

            int old = a[k];

            // REMOVE k from old value

            auto &S1 = pos[old];

            auto it = S1.find(k);

            int pred = 0;
            int succ = 0;

            if (it != S1.begin()) {
                auto p = std::prev(it);
                pred = *p;
            }

            auto nxt = next(it);
            if (nxt != S1.end()) {
                succ = *nxt;
            }

            if (succ) {
                set_prev(succ, pred);
            }

            S1.erase(it);

            // INSERT k into new value

            auto &S2 = pos[u];

            auto it2 = S2.lower_bound(k);

            pred = 0;
            succ = 0;

            if (it2 != S2.begin()) {
                auto p = std::prev(it2);
                pred = *p;
            }

            if (it2 != S2.end()) {
                succ = *it2;
            }

            S2.insert(k);

            set_prev(k, pred);

            if (succ) {
                set_prev(succ, k);
            }

            a[k] = u;
        }
        else {
            int l, r;
            cin >> l >> r;

            int mx = seg.query(1, 1, n, l, r);

            cout << (mx < l ? "YES" : "NO") << '\n';
        }
    }

    return 0;
}