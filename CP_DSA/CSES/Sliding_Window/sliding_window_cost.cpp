#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

multiset<ll> low, high;
ll sumLow = 0, sumHigh = 0;

void balance() {
    while (low.size() > high.size() + 1) {
        auto it = prev(low.end());
        ll x = *it;

        sumLow -= x;
        low.erase(it);

        high.insert(x);
        sumHigh += x;
    }

    while (low.size() < high.size()) {
        auto it = high.begin();
        ll x = *it;

        sumHigh -= x;
        high.erase(it);

        low.insert(x);
        sumLow += x;
    }
}

void add(ll x) {
    if (low.empty() || x <= *prev(low.end())) {
        low.insert(x);
        sumLow += x;
    } else {
        high.insert(x);
        sumHigh += x;
    }
    balance();
}

void remove_(ll x) {
    auto it = low.find(x);

    if (it != low.end()) {
        sumLow -= x;
        low.erase(it);
    } else {
        it = high.find(x);
        sumHigh -= x;
        high.erase(it);
    }

    balance();
}

ll cost() {
    ll med = *prev(low.end());

    return med * (ll)low.size() - sumLow
         + sumHigh - med * (ll)high.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, k;
    cin >> n >> k;

    vector<ll> arr(n + 1);

    for (ll i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for (ll i = 1; i <= k; i++) {
        add(arr[i]);
    }

    cout << cost();

    for (ll i = k + 1; i <= n; i++) {
        remove_(arr[i - k]);
        add(arr[i]);

        cout << " " << cost();
    }

    cout << '\n';
}