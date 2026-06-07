// ::: Need to have a deep look
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Movie {
    int s, e;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<Movie> movies(n);

    for (int i = 0; i < n; i++) {
        cin >> movies[i].s >> movies[i].e;
    }

    sort(movies.begin(), movies.end(),
         [](const Movie& a, const Movie& b) {
             if (a.s != b.s) return a.s < b.s;
             return a.e < b.e;
         });

    vector<int> starts(n);

    for (int i = 0; i < n; i++) {
        starts[i] = movies[i].s;
    }

    // bestIdx[i] = movie with minimum ending time in suffix [i..n-1]
    vector<int> bestIdx(n);

    bestIdx[n - 1] = n - 1;

    for (int i = n - 2; i >= 0; i--) {
        if (movies[i].e < movies[bestIdx[i + 1]].e)
            bestIdx[i] = i;
        else
            bestIdx[i] = bestIdx[i + 1];
    }

    const int LOG = 20;

    vector<vector<int>> up(n + 1, vector<int>(LOG, n));

    // nxt movie after taking movie i
    for (int i = 0; i < n; i++) {

        int pos = lower_bound(
            starts.begin(),
            starts.end(),
            movies[i].e
        ) - starts.begin();

        if (pos < n)
            up[i][0] = bestIdx[pos];
        else
            up[i][0] = n;
    }

    for (int j = 1; j < LOG; j++) {
        for (int i = 0; i <= n; i++) {
            up[i][j] = up[up[i][j - 1]][j - 1];
        }
    }

    while (q--) {

        int a, b;
        cin >> a >> b;

        int pos = lower_bound(
            starts.begin(),
            starts.end(),
            a
        ) - starts.begin();

        if (pos == n) {
            cout << 0 << '\n';
            continue;
        }

        int cur = bestIdx[pos];

        if (movies[cur].e > b) {
            cout << 0 << '\n';
            continue;
        }

        long long ans = 1;

        for (int j = LOG - 1; j >= 0; j--) {

            int nxt = up[cur][j];

            if (nxt < n && movies[nxt].e <= b) {
                ans += (1LL << j);
                cur = nxt;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}