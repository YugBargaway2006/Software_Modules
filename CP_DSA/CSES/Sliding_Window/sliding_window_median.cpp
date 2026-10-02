#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ll n, k;
vector<ll> arr;
multiset<ll> num;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    arr.assign(n + 1, 0);

    for (ll i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    vector<ll> ans;

    for (ll i = 1; i <= k; i++) {
        num.insert(arr[i]);
    }

    auto it = num.begin();
    advance(it, (k - 1) / 2);

    ans.push_back(*it);

    for (ll i = k + 1; i <= n; i++) {
        ll add = arr[i];
        ll rem = arr[i - k];

        num.insert(add);

        if (add < *it) it--;

        if (rem <= *it) it++;

        num.erase(num.lower_bound(rem));

        ans.push_back(*it);
    }

    for (auto x : ans) cout << x << " ";
    cout << endl;
}