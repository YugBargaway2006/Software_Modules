/*
    Solutions:
    1. Parity of set bits cannot be changed.
    2. Save odd and even position seperately, calculate difference, sum, return;

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define endl '\n'

ll calculate(vector<ll>& a, vector<ll>& b) {
    ll n = a.size();
    ll ca = accumulate(a.begin(), a.end(), 0LL), cb = accumulate(b.begin(), b.end(), 0LL);
    if(ca != cb) return -1;

    vector<ll> ta, tb;
    for(ll i = 0; i < n; i++) {
        if(a[i] == 1) {
            ta.push_back(i);
        }
        if(b[i] == 1) {
            tb.push_back(i);
        }
    }

    ll ans = 0;
    for(ll i = 0; i < ta.size(); i++) {
        ans += abs(ta[i] - tb[i]);
    }
    return ans;
}

void solve() {
    ll n; cin >> n;
    vector<ll> a0, b0, a1, b1;
    for(ll i = 0; i < n; i++) {
        char x; cin >> x;
        if(x == '1' && i % 2 == 0) {
            a0.push_back(1);
        } else if(x == '0' && i % 2 == 0) {
            a0.push_back(0);
        } else if(x == '1' && i % 2 == 1) {
            a1.push_back(1);
        } else if(x == '0' && i % 2 == 1) {
            a1.push_back(0);
        }
    } 

    for(ll i = 0; i < n; i++) {
        char x; cin >> x;
        if(x == '1' && i % 2 == 0) {
            b0.push_back(1);
        } else if(x == '0' && i % 2 == 0) {
            b0.push_back(0);
        } else if(x == '1' && i % 2 == 1) {
            b1.push_back(1);
        } else if(x == '0' && i % 2 == 1) {
            b1.push_back(0);
        }
    } 

    ll num1 = calculate(a0, b0);
    ll num2 = calculate(a1, b1);

    if(num1 == -1 || num2 == -1) {
        cout << -1 << endl;
        return;
    }

    cout << (num1 + num2) << endl;
}


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t; cin >> t; 
    while(t--) {
        solve();
    }
}