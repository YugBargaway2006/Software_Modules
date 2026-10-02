#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ll cross(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c) {
    return (b.first - a.first) * (c.second - a.second)
         - (b.second - a.second) * (c.first - a.first);
}

bool onSegment(ll x1, ll y1, ll x2, ll y2,
               ll x3, ll y3) {
    return min(x1,x2) <= x3 && x3 <= max(x1,x2) &&
           min(y1,y2) <= y3 && y3 <= max(y1,y2);
}

void solve() {
    vector<pair<ll, ll>> point(4);

    cin >> point[0].first >> point[0].second
        >> point[1].first >> point[1].second
        >> point[2].first >> point[2].second
        >> point[3].first >> point[3].second;

    pair<ll,ll> A = point[0];
    pair<ll,ll> B = point[1];
    pair<ll,ll> C = point[2];
    pair<ll,ll> D = point[3];

    ll o1 = cross(A,B,C);
    ll o2 = cross(A,B,D);
    ll o3 = cross(C,D,A);
    ll o4 = cross(C,D,B);

    if(o1 == 0 && onSegment(A.first,A.second,B.first,B.second,C.first,C.second)) {
        cout << "YES" << endl;
        return;
    }

    if(o2 == 0 && onSegment(A.first,A.second,B.first,B.second,D.first,D.second)) {
        cout << "YES" << endl;
        return;
    }

    if(o3 == 0 && onSegment(C.first,C.second,D.first,D.second,A.first,A.second)) {
        cout << "YES" << endl;
        return;
    }

    if(o4 == 0 && onSegment(C.first,C.second,D.first,D.second,B.first,B.second)) {
        cout << "YES" << endl;
        return;
    }

    if((o1 > 0) != (o2 > 0) &&
       (o3 > 0) != (o4 > 0))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t;
    cin >> t;

    while(t--) solve();
}