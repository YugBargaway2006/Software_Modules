#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
    const int N = 2000;

    vector<int> grundy(N + 1);

    for (int n = 3; n <= N; n++) {
        vector<bool> vis(512);

        for (int a = 1; a < n - a; a++) {
            int b = n - a;
            vis[grundy[a] ^ grundy[b]] = true;
        }

        int mex = 0;
        while (vis[mex]) mex++;
        grundy[n] = mex;
    }

    vector<bool> losing(N + 1);

    for (int i = 1; i <= N; i++) {
        if (grundy[i] == 0) losing[i] = true;
    }

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        if (n > 2000) {
            cout << "first\n";
        } else {
            cout << (losing[n] ? "second" : "first") << endl;
        }
    }
}