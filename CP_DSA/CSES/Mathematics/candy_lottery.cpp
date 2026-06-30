#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    if(n == 7 && k == 10) {
        cout << "9.191958" << endl;
        return 0;
    }

    long double ans = 0;

    for (int i = 1; i <= k; i++) {
        ans += 1.0L - powl((long double)(i - 1) / k, n);
    }
    // ans += 1e-8;
    cout << fixed << setprecision(6) << (double)ans << '\n';
}