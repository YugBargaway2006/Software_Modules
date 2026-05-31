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
 
int peg(int a, int b) {
    bool f = !((a == 1) || (b == 1));
    bool s = !((a == 2) || (b == 2));
    bool t = !((a == 3) || (b == 3));
 
    return 1*f + 2*s + 3*t;
}
 
void hanoi(int n, int s, int t) {
    // cerr << n << " " << s << " " << t << endl;
    if(n == 0) return;
    if(n == 1) {
        cout << s << " " << t << endl;
        return;
    } 
    hanoi(n-1, s, peg(s, t));
    cout << s << " " << t << endl;
    hanoi(n-1, peg(s, t), t);
}
 
 
void solve() {
    int n; cin >> n;
    
    cout << pow(2, n) - 1 << endl;
 
    hanoi(n, 1, 3);
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
