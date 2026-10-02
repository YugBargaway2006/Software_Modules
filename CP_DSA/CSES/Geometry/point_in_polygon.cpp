#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

struct Point {
    ll x, y;
};

ll cross(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y)
         - (b.y - a.y) * (c.x - a.x);
}

bool onSegment(Point a, Point b, Point p) {
    return cross(a, b, p) == 0 &&
           min(a.x, b.x) <= p.x && p.x <= max(a.x, b.x) &&
           min(a.y, b.y) <= p.y && p.y <= max(a.y, b.y);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;

    vector<Point> poly(n);

    for(ll i = 0; i < n; i++) {
        cin >> poly[i].x >> poly[i].y;
    }

    while(m--) {
        Point p;
        cin >> p.x >> p.y;

        bool boundary = false;
        ll cnt = 0;

        for(ll i = 0; i < n; i++) {
            Point a = poly[i];
            Point b = poly[(i + 1) % n];

            if(onSegment(a, b, p)) {
                boundary = true;
                break;
            }

            if((a.y > p.y) != (b.y > p.y)) {
                ll c = cross(a, b, p);

                if((b.y > a.y && c > 0) ||
                   (b.y < a.y && c < 0))
                    cnt++;
            }
        }

        if(boundary) {
            cout << "BOUNDARY" << endl;
        } else if(cnt & 1) {
            cout << "INSIDE" << endl;
        } else {
            cout << "OUTSIDE" << endl;
        }
    }
}