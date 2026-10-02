#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define endl '\n'

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s; cin >> s;
    string ans;
    set<char> st;

    for (char c : s) {
        st.insert(c);

        if (st.size() == 4) {
            ans += c;
            st.clear();
        }
    }

    for (char c : {'A','C','G','T'}) {
        if (!st.count(c)) {
            ans += c;
            break;
        }
    }

    cout << ans << '\n';
}