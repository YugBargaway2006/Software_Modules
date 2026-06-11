// : :::::::::::: REVISE Badly with Visualization
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, k;
    cin >> n >> k;

    ordered_set<ll> st;
    for(ll i = 1; i <= n; i++) st.insert(i);

    ll idx = 0;

    while(!st.empty()) {
        idx = (idx + k) % st.size();
        auto it = st.find_by_order(idx);
        cout << *it << " ";
        st.erase(it);
    }

    cout << '\n';
}