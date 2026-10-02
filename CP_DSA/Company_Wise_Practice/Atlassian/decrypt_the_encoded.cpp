// Write your code here
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ll sti(string& s) {
    return stoll(s);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s; cin >> s;
    ll d = s.size();
    ll prob = static_cast<ll>(s[0] - '0');

    ll mx = 0;
    ll mn = 1e15;
    for(ll i = 0; i < 10; i++) {   // to 
        for(ll j = 0; j < 10; j++) {    // from
            if(i == 0 && j == prob) {
                continue;
            }

            string temp = s;
            for(auto& x : temp) {
                if(static_cast<ll>(x - '0') == j) {
                    x = static_cast<char>(i + '0');
                }
            } 

            ll v = sti(temp);
            mx = max(mx, v);
            mn = min(mn, v);
        }
    }
    // cout << mx << " " << mn << endl;
    cout << mx - mn << endl;
}