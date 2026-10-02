// Write your code here
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        string s;
        cin >> s;

        int n = (int)s.size();
        vector<long long> ans(n, 0);

        int i = 0;

        while (i < n) {
            if (s[i] == 'R') {
                int rStart = i;

                while (i < n && s[i] == 'R') i++;
                int rl = i - 1;      // last R

                int lStart = i;

                while (i < n && s[i] == 'L') i++;
                int lr = lStart;     // first L

                long long r = rl - rStart + 1;
                long long l = i - lStart;

                ans[rl] =
                    (r + 1) / 2 + l / 2;

                ans[lr] =
                    r / 2 + (l + 1) / 2;
            }
        }

        for (long long x : ans) cout << x;
        cout << '\n';
    }

    return 0;
}