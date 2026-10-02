#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W;
    ll K;
    cin >> H >> W >> K;

    vector<vector<int>> a(H, vector<int>(W));

    for (int i = 0; i < H; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < W; j++)
            a[i][j] = s[j] - '0';
    }

    ll ans = 0;

    vector<int> col(W);

    for (int top = 0; top < H; top++) {

        fill(col.begin(), col.end(), 0);

        for (int bottom = top; bottom < H; bottom++) {

            // Add one more row
            for (int j = 0; j < W; j++)
                col[j] += a[bottom][j];

            unordered_map<ll, ll> freq;
            freq[0] = 1;

            ll prefix = 0;

            for (int j = 0; j < W; j++) {
                prefix += col[j];
                ans += freq[prefix - K];
                freq[prefix]++;
            }
        }
    }

    cout << ans << '\n';
}