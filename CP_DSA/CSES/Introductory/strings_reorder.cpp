// 11 : 26  ::::::: REVISE
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int n = (int)s.size();

    vector<int> cnt(26, 0);
    for(char c : s) cnt[c - 'A']++;

    string ans;
    ans.reserve(n);

    for(int pos = 0; pos < n; pos++) {
        bool found = false;
        for(int ch = 0; ch < 26; ch++) {
            if(cnt[ch] == 0) continue;
            if(!ans.empty() && ans.back() == char('A' + ch)) continue;

            cnt[ch]--;
            int rem = n - pos - 1;
            bool ok = true;
            for(int c = 0; c < 26; c++) {
                int limit;

                if(c == ch)
                    limit = rem / 2;
                else
                    limit = (rem + 1) / 2;

                if(cnt[c] > limit) {
                    ok = false;
                    break;
                }
            }

            if(ok) {
                ans.push_back(char('A' + ch));
                found = true;
                break;
            }

            cnt[ch]++;
        }

        if(!found) {
            cout << -1 << '\n';
            return 0;
        }
    }

    cout << ans << '\n';
    return 0;
}