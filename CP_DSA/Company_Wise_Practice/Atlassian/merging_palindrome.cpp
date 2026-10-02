#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {
    string a, b;
    cin >> a >> b;

    vector<int> fa(26, 0), fb(26, 0);

    for (char c : a) fa[c - 'a']++;
    for (char c : b) fb[c - 'a']++;

    vector<int> half(26, 0);

    // All available pairs
    for (int i = 0; i < 26; i++)
        half[i] = fa[i] / 2 + fb[i] / 2;

    int common = -1;
    for (int i = 0; i < 26; i++) {
        if ((fa[i] & 1) && (fb[i] & 1)) {
            common = i;
            break;
        }
    }

    int center = -1;
    if (common != -1) {
        // Two odd copies become one extra pair
        half[common]++;
    } else {
        for (int i = 0; i < 26; i++) {
            if ((fa[i] & 1) || (fb[i] & 1)) {
                center = i;
                break;
            }
        }
    }

    string left;
    for (int i = 0; i < 26; i++)
        left.append(half[i], char('a' + i));

    string ans = left;
    if (center != -1)
        ans.push_back(char('a' + center));

    reverse(left.begin(), left.end());
    ans += left;

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
        solve();

    return 0;
}