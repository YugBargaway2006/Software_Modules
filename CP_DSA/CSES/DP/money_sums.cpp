// 22 : 25   ::: Dont use and push
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'



signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n; cin >> n;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());  // O(nlgn)

    unordered_set<ll> val, nxt;
    for(auto& x : arr) {  // O(n)
        for(auto& r : val) {  // O(n3)
            // if(val.count(r+x) == 0)cout << x << " -> " << (r+x) << endl;
            nxt.insert(r+x); // O(1) (Amortized)
            nxt.insert(r);
        }
        nxt.insert(x); // O(1) (Amortized)
        val = move(nxt);
        nxt.clear();
    }

    cout << val.size() << endl;
    vector<ll> ans;
    for(auto v : val) ans.push_back(v);
    sort(ans.begin(), ans.end());
    for(auto v : ans) cout << v << " "; cout << endl;
}