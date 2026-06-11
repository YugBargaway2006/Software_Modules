// :::::::::: Manecher with different style propagation
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();

    vector<int> ol(n), el(n);

    // odd
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int len = (i > r) ? 1 : min(ol[l + r - i], r - i + 1);
        while (i - len >= 0 && i + len < n && s[i - len] == s[i + len]) len++;
        ol[i] = len--;
        if (i + len > r) {
            l = i - len;
            r = i + len;
        }
    }

    // even
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int len = (i > r) ? 0 : min(el[l + r - i + 1], r - i + 1);
        while (i - len - 1 >= 0 && i + len < n && s[i - len - 1] == s[i + len]) len++;
        el[i] = len--;
        if (i + len > r) {
            l = i - len - 1;
            r = i + len;
        }
    }

    vector<int> ans(n, 1);

    for (int i = 0; i < n; i++) {
        ans[i + ol[i] - 1] = max(ans[i + ol[i] - 1], 2 * ol[i] - 1);
    }

    for (int i = 0; i < n; i++) {
        if (el[i] > 0)
            ans[i + el[i] - 1] = max(ans[i + el[i] - 1], 2 * el[i]);
    }

    for (int i = n - 2; i >= 0; i--) {
        ans[i] = max(ans[i], ans[i + 1] - 2);
    }

    for (int x : ans) cout << x << ' ';
}