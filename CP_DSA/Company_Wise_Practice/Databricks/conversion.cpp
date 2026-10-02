// Write your code here
#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define endl '\n'

bool lower(char c) {
    return (c <= 'z') && (c >= 'a');
}

void solve() {
    string s; 
    getline(cin >> ws, s);
    string ans = "";

    ll n = s.size();
    for(ll i = 0; i < n; i++) {
        if(i+1 < n && s[i] == '`' && lower(s[i+1])) {
            ll j = i+1;
            string word = "";
            bool caps = false;
            while(j < n && s[j] != '`') {
                if(s[j] == '_') {
                    caps = true;
                    j++;
                } else {
                    if(caps) {
                        word += toupper(s[j]);
                        caps = false;
                    } else {
                        word += s[j];
                    }
                    j++;
                }
            }
            i = j;
            ans += word;
        } else {
            if(s[i] != '`') ans += s[i];
        }
    }
    cout << ans << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t; cin >> t;
    cin.ignore();
    while(t--) {
        solve();
    }
}