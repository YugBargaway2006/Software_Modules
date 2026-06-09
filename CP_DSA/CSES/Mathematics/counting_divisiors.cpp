// 13 : 58  :::::::: Remember Divisors formula
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

vector<int> divisors(1e6 + 1, 0);

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for(int i = 1; i <= 1e6; i++) {
        for(int j = i; j <= 1e6; j += i) {
            divisors[j]++;
        }
    }

    int t;
    cin >> t;

    while(t--) {
        int x;
        cin >> x;
        cout << divisors[x] << endl;
    }
}