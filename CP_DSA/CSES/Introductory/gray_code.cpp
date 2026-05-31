#include <bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define int long long 
#define INT_MAX LLONG_MAX
#define vi vector<long long>
#define pi pair<int, int>
#define f(i,k,n) for(int i = k; i < n; i++)
#define mi map<int, int>
#define si set<int>
#define debug(i) cout << i << endl

 
void solve() {
    int n; cin >> n;
    int l = pow(2, n);
    f(i,0,l) {
        string code = "";
        string binary_str = "";
        int temp = i;
        for(int j = n - 1; j >= 0; j--) {
            binary_str += ((temp >> j) & 1) ? '1' : '0';
        }
        code += binary_str[0];
        f(i,1,n) {
            code += (binary_str[i-1] - '0') ^ (binary_str[i] - '0') + '0';
        }
        cout << code << endl;
    }
}
 
 
signed main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t = 1; 
    // cin >> t;
 
    while(t--) {
        solve();
    }
    return 0;
}