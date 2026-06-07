#include <bits/stdc++.h>
using namespace std;

class BIT2D {
public:
    int n;
    vector<vector<int>> bit;

    BIT2D(int N) {
        n = N;
        bit.assign(n + 1, vector<int>(n + 1, 0));
    }

    void add(int x, int y, int val) {
        for (int i = x; i <= n; i += i & -i) {
            for (int j = y; j <= n; j += j & -j) {
                bit[i][j] += val;
            }
        }
    }

    int sum(int x, int y) {
        int res = 0;

        for (int i = x; i > 0; i -= i & -i) {
            for (int j = y; j > 0; j -= j & -j) {
                res += bit[i][j];
            }
        }

        return res;
    }

    int query(int x1, int y1, int x2, int y2) {
        return sum(x2, y2)
             - sum(x1 - 1, y2)
             - sum(x2, y1 - 1)
             + sum(x1 - 1, y1 - 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<string> grid(n + 1);

    BIT2D bit(n);

    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;

        grid[i] = " " + s; // 1-indexing

        for (int j = 1; j <= n; j++) {
            if (grid[i][j] == '*') {
                bit.add(i, j, 1);
            }
        }
    }

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int x, y;
            cin >> x >> y;

            if (grid[x][y] == '*') {
                grid[x][y] = '.';
                bit.add(x, y, -1);
            } else {
                grid[x][y] = '*';
                bit.add(x, y, +1);
            }
        }
        else {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;

            cout << bit.query(x1, y1, x2, y2) << '\n';
        }
    }

    return 0;
}