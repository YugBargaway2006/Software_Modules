// 22 : 52
#include <bits/stdc++.h>
using namespace std;

#define ll uint32_t
#define endl '\n'

ll n, k;
ll x, a, b, c; 
int bits[30];

inline ll next(ll x) {
    return ((long long)a*x + b) % c;
}

inline void add(ll& sum, ll u) {
    sum |= u;
    while(u) {
        int b = __builtin_ctz(u);
        bits[b]++;
        u &= (u - 1);
    }
} 

inline void remove(ll& sum, ll u) {
    while(u) {
        int b = __builtin_ctz(u);
        if(--bits[b] == 0)
            sum ^= (1u << b);
        u &= (u - 1);
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    cin >> x >> a >> b >> c;

    ll ans = 0;
    ll sum = 0;
    add(sum, x);
    ll back = x;
    ll front = x;
    for(ll i = 0; i < k-1; i++) {
        front = next(front);
        // cout << sum << endl;
        // for(ll i = 0; i < 5; i++) cout << bits[i] << " "; cout << endl;
        add(sum, front);
    }
    // cout << sum << endl;

    ll i = k;
    while(i <= n) {
        // cout << sum << endl;
        ans ^= sum;
        if(i == n) break;
        remove(sum, back);
        // cout << sum << endl;
        back = next(back);
        front = next(front);
        add(sum, front);
        i++;
    }
    cout << ans << endl;
}