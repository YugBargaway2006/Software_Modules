#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ll cross(pair<ll, ll> A, pair<ll, ll> B, pair<ll, ll> C) {
    return (A.first - B.first) * (A.second - C.second) - (A.second - B.second) * (A.first - C.first);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n; cin >> n;
    ll x1, y1; cin >> x1 >> y1;
    pair<ll, ll> A; cin >> A.first >> A.second;
    ll ans = 0;
    for(ll i = 2; i < n; i++) {
        pair<ll, ll> C; cin >> C.first >> C.second;
        ans += cross({x1, y1}, A, C);
        A = C;
    }
    cout << abs(ans) << endl;
}