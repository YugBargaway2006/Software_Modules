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
 
int gcd(int a, int b);
void printArray(const vector<int>& a);
int nextPower2(int n);
int binexp(int base, int power, int mod);
int modInverse(int a, int mod);
 
 
 
 
 
void solve() {
    int n; cin >> n;
    vi a(n);
    f(i,0,n) {
        cin >> a[i];
    }
 
    int sum = accumulate(a.begin(), a.end(), 0LL);
 
    unordered_set<int> ach;
    ach.insert(0);
    for(int i = 0; i < n; i++) {
        unordered_set<int> curr = ach;
        for(auto e : ach) {
            curr.insert(e+a[i]);
        }
        ach = curr;
    }
 
    int ans = INT_MAX;
    for(auto e : ach) {
        ans = min(ans, abs(sum - e - e));
    }
    cout << ans << endl;
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
