#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve() {

}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s; cin >> s;
    string ans = "";
    for(auto c : s) {
        if(c >= '0' && c <= '9') ans.push_back(c);
    }
    cout << ans << endl;
}