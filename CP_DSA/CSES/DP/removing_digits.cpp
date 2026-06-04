// 12 : 47
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ll n;

ll calculate(ll n) {
    ll d = 0;
    while(n != 0) {
        d = max(d, n % 10);
        n /= 10;
    }
    return d;
}

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    ll ct = 0;
    while(n != 0) {
        ct++;
        n -= calculate(n);
    }
    cout << ct << endl;
}