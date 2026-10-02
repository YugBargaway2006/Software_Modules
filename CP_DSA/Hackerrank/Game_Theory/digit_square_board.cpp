#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<vector<int>> pre;
vector<vector<vector<vector<int>>>> dp;

bool isPrime(int x) {
    if(x < 2) return false;
    for(int i = 2; i * i <= x; i++) {
        if(x % i == 0) return false;
    }
    return true;
}

bool terminal(int ui, int uj, int li, int lj) {
    if(ui == li && uj == lj) return true;

    int sum = pre[li][lj];

    if(ui > 0) sum -= pre[ui - 1][lj];
    if(uj > 0) sum -= pre[li][uj - 1];
    if(ui > 0 && uj > 0) sum += pre[ui - 1][uj - 1];

    return sum == 0;
}

int grundy(int ui, int uj, int li, int lj) {
    if(terminal(ui, uj, li, lj))
        return 0;

    int &ans = dp[ui][uj][li][lj];
    if(ans != -1) return ans;

    bool seen[64] = {};

    for(int r = ui; r < li; r++) {
        int g1 = grundy(ui, uj, r, lj);
        int g2 = grundy(r + 1, uj, li, lj);
        seen[g1 ^ g2] = true;
    }

    for(int c = uj; c < lj; c++) {
        int g1 = grundy(ui, uj, li, c);
        int g2 = grundy(ui, c + 1, li, lj);
        seen[g1 ^ g2] = true;
    }

    ans = 0;
    while(seen[ans]) ans++;

    return ans;
}

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(n));

    pre.assign(n, vector<int>(n, 0));

    dp.assign(
        n,
        vector<vector<vector<int>>>(
            n,
            vector<vector<int>>(
                n,
                vector<int>(n, -1)
            )
        )
    );

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int x;
            cin >> x;

            arr[i][j] = !isPrime(x);

            pre[i][j] = arr[i][j];

            if(i) pre[i][j] += pre[i - 1][j];
            if(j) pre[i][j] += pre[i][j - 1];
            if(i && j) pre[i][j] -= pre[i - 1][j - 1];
        }
    }

    int g = grundy(0, 0, n - 1, n - 1);

    cout << (g ? "First" : "Second") << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while(T--) solve();

    return 0;
}