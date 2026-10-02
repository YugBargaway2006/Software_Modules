// 22 : 52
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ll n, k;
ll x, a, b, c; 

ll next(ll x) {
    return (a*x + b) % c;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    cin >> x >> a >> b >> c;

    ll ans = 0;
    ll sum = x;
    ll back = x;
    ll front = x;
    for(ll i = 0; i < k-1; i++) {
        front = next(front);
        // cout << front << endl;
        sum += front;
    }
    // cout << sum << endl;

    ll i = k;
    while(i <= n) {
        // cout << sum << endl;
        ans ^= sum;
        sum -= back;
        back = next(back);
        front = next(front);
        sum += front;
        i++;
    }
    cout << ans << endl;
}