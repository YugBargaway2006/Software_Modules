#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

struct pt {
    ll x, y;
};

ll n;
vector<pt> arr;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    arr.resize(n);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i].x >> arr[i].y;
    }

    sort(arr.begin(), arr.end(), [&](const pt& a, const pt& b) {
        if(a.x == b.x) return a.y < b.y;
        return a.x < b.x;
    });

    // for(auto p : arr) cout << p.x << " " << p.y << endl;
    // cout << endl;

    ll res = 0;
    ll mxn = 1e6;
    ll mnx = mxn, mny = mxn;
    for(ll i = 0; i < n; i++) {
        pt p = arr[i];
        if(!(mnx < p.x && mny < p.y)) {
            // cout << p.x << " " << p.y << endl;
            res++;
        }
        mnx = min(mnx, p.x);
        mny = min(mny, p.y);
    }
    cout << res << endl;
}