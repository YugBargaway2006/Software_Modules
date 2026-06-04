// ::: REVISE
#include <bits/stdc++.h>
using namespace std;
 
// #define endl '\n'
#define int long long 
#define INT_MAX LLONG_MAX
#define vi vector<int>
#define pi pair<int, int>
#define f(i,k,n) for(int i = k; i < n; i++)
#define mi map<int>
#define si set<int>
#define debug(i) cout << i << endl
 
 
void solve() {
    int n, x; cin >> n >> x;
 
    vi h(n), s(n);
    f(i,0,n) {
        cin >> h[i];
    }
    f(i,0,n) {
        cin >> s[i];
    }

    vi memo(x+1, 0);
 
    f(i,1,n+1) {
        for(int j = x; j >= h[i-1]; j--) {
            memo[j] = max(memo[j], memo[j-h[i-1]] + s[i-1]);
        }
    }
 
    cout << memo[x] << endl;
 
    
}
 
 
signed main() {
    // ios::sync_with_stdio(false); cin.tie(NULL);
    // int t; cin >> t;
    int t = 1;
    while(t--) {
        // cout << "solve called" << endl;
        solve();
    }
}
