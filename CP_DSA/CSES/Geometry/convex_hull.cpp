// 17 : 34
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

struct pt {
    ll x, y;
};

bool turns_left(pt& a, pt &b, pt& c) {
    // cout << a.x << " " << a.y << " " << b.x << " " << b.y << " " << c.x << " " << c.y << endl;
    ll res = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    if(res > 0) return true;
    return false;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n; cin >> n;
    vector<pt> arr(n);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i].x >> arr[i].y;
    }

    sort(arr.begin(), arr.end(), [](const pt a, const pt b) {
        if(a.x == b.x) {
            return a.y < b.y;
        }
        return a.x < b.x;
    });

    vector<pt> hull;

    pt st = arr[0];
    hull.push_back(arr[0]);
    hull.push_back(arr[1]);
    for(ll i = 2; i < n; i++) {
        ll m = hull.size();
        while(m >= 2 && turns_left(hull[m-2], hull[m-1], arr[i])) {
            hull.pop_back();
            m--;
        }
        hull.push_back(arr[i]);
        // cout << m << endl;
    }
    ll saved = hull.size();
    for(ll i = n-2; i >= 0; i--) {
        ll m = hull.size();
        while(m >= saved+1 && turns_left(hull[m-2], hull[m-1], arr[i])) {
            hull.pop_back();
            m--;
        }
        hull.push_back(arr[i]);
    }
    hull.pop_back();

    cout << hull.size() << endl;
    for(auto& p : hull) cout << p.x << " " << p.y << endl;
}