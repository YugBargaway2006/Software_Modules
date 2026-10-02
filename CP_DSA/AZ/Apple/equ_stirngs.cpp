// Write your code here
#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define endl '\n'

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s, t; cin >> s >> t;
    if(s.size() != t.size()) {
        cout << "NO" << endl;
        return 0;
    }

    vector<ll> freqs(26, 0), freqt(26, 0);
    for(ll i = 0; i < s.size(); i++) {
        freqs[s[i]-'a']++;
        freqt[t[i]-'a']++;
    }

    for(ll i = 0; i < 26; i++) {
        if(abs(freqs[i] - freqt[i]) > 3) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
}