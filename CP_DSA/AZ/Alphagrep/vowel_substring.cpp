// http://maang.in/contests/attempts/86601?problem_id=521

// Write your code here
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'


void solve() {
    string s; cin >> s;
    ll n = s.size();
    ll ct = 0;
    ll l = -1;
    vector<ll> idx = {-1, -1, -1, -1, -1};
    map<char, ll> vow = {{'a', 0}, {'e', 1}, {'i', 2}, {'o', 3}, {'u', 4}};

    for(ll i = 0; i < n; i++) {
        char c = s[i];
        if(vow.count(c) == 0) {
            l = i;
            continue;
        }

        idx[vow[c]] = i;
        bool good = true;
        ll mn = n;
        for(ll i = 0; i < 5; i++) {
            if(idx[i] <= l) good = false; 
            mn = min(mn, idx[i]);
        }
        if(!good) {
            continue;
        }

        ct += (mn - l);
    }
    cout << ct << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t; cin >> t;
    while(t--) {
        solve();
    }
}