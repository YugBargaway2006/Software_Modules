#include <bits/stdc++.h>
using namespace std;

using u32 = uint32_t;
using ull = unsigned long long;

u32 a, b, c;

inline u32 nxt(u32 x) {
    return ((ull)a * x + b) % c;
}

struct StackOR {
    vector<pair<u32,u32>> st; // {value, prefix_or}

    inline void push(u32 x) {
        u32 cur = st.empty() ? x : (st.back().second | x);
        st.push_back({x, cur});
    }

    inline void pop() {
        st.pop_back();
    }

    inline bool empty() const {
        return st.empty();
    }

    inline u32 agg() const {
        return st.empty() ? 0 : st.back().second;
    }

    inline u32 top() const {
        return st.back().first;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    u32 n, k, x;
    cin >> n >> k;
    cin >> x >> a >> b >> c;

    StackOR in, out;

    auto push_q = [&](u32 v) {
        in.push(v);
    };

    auto pop_q = [&]() {
        if (out.empty()) {
            while (!in.empty()) {
                u32 v = in.top();
                in.pop();

                u32 cur = out.empty() ? v : (out.agg() | v);
                out.st.push_back({v, cur});
            }
        }
        out.pop();
    };

    auto query = [&]() -> u32 {
        return in.agg() | out.agg();
    };

    u32 cur = x;

    for (u32 i = 1; i <= k; i++) {
        push_q(cur);
        cur = nxt(cur);
    }

    u32 ans = query();

    for (u32 i = k + 1; i <= n; i++) {
        pop_q();
        push_q(cur);
        cur = nxt(cur);

        ans ^= query();
    }

    cout << ans << '\n';
}