// 22 : 56  ::::::::: Manacher Algorithm
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s; cin >> s;
    ll n = s.size();
    vector<ll> ol(n), el(n);

    // For Odd len
    for(ll i = 0, l = 0, r = -1; i < n; i++) {
        ll len = (i > r) ? 1 : min(ol[l+r-i], r-i+1);
        while(0 <= i - len && i + len < n && s[i-len] == s[i+len]) {
            len++;
        } 

        ol[i] = len--;
        if(i + len > r) {
            l = i - len;
            r = i+len;
        }
    }

    // Even-length
    for(ll i = 0, l = 0, r = -1; i < n; i++) {
        ll len = (i > r) ? 0 : min(el[l+r-i+1], r-i+1);
        while(0 <= i - len - 1 && i + len < n && s[i-len-1] == s[i+len]) {
            len++;
        } 

        el[i] = len--;
        if(i + len > r) {
            l = i - len - 1;
            r = i+len;
        }
    }

    ll ml = 0, cen = -1;
    for(ll i = 0; i < n; i++) {
        if(ol[i]*2-1>ml) {
            ml = ol[i] * 2 - 1;
            cen = i;
        }
        if(el[i]*2>ml) {
            ml = el[i] * 2 ;
            cen = i;
        }
    }

    cout << s.substr(cen-ml/2,ml) << endl;
}