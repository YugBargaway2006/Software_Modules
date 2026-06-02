// *** 16 : 37 
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

multiset<int> price;

signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        price.insert(x);
    }

    while(m--) {
        int b; cin >> b;
        auto it = price.upper_bound(b);
        if(it == price.begin()) cout << -1 << endl;
        else {
            auto res = prev(it);
            cout << *res << endl;
            price.erase(res);
        }
    }
}

// 16 : 58