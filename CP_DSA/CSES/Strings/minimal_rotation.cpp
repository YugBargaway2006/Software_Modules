#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
signed main() {
    string s; cin >> s;
    int n = s.size();
 
    s += s; 
    vector<int> f(2*n, -1);
 
    int k = 0; 
 
    for(int j = 1; j < 2*n; j++) {
        int i = f[j - k - 1];
 
        while(i != -1 && s[j] != s[k + i + 1]) {
            if(s[j] < s[k + i + 1]) {
                k = j - i - 1;
            }
            i = f[i];
        }
 
        if(s[j] != s[k + i + 1]) {
            if(s[j] < s[k]) {
                k = j;
            }
            f[j - k] = -1;
        } else {
            f[j - k] = i + 1;
        }
    }
 
    cout << s.substr(k, n) << '\n';
}
