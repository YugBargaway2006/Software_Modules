#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n;
    cin >> m;

    vector<int> a(m), b(m);
    for (int i = 0; i < m; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    vector<int> bad(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int x = a[i];
        int y = b[i];

        if (x > y) swap(x, y);

        bad[y] = max(bad[y], x);
    }

    long long ans = 0;
    int mx = 0;

    for (int r = 1; r <= n; r++) {
        mx = max(mx, bad[r]);
        ans += (r - mx);
    }

    cout << ans << '\n';
    return 0;
}