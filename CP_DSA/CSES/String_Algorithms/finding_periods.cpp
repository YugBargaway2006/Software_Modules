#include <iostream>
#include <vector>
using namespace std;

#define int long long

vector<int> z_fn(string s) {
    int n = s.size();
    vector<int> z(n);

    int l = 0, r = 0;
    for(int i = 1; i < n; i++)  {
        if(i <= r) z[i] = min(r - i + 1, z[i-l]);

        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;

        if(i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

signed main() {
    string s; cin >> s;
    int n = s.size();

    vector<int> z = z_fn(s);
    for(int k = 1; k <= n; k++) {
        if(k == n || z[k] >= n - k) cout << k << " ";
    }
    cout << endl;
}