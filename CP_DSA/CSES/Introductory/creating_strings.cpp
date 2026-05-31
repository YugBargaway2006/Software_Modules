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
    string s; cin >> s;
    
    set<string> all;
    // int i = 0;
    while(all.count(s) ==0) {
        all.insert(s);
        next_permutation(s.begin(), s.end());
        // i++;
    }
 
    cout << all.size() << endl;
    for(auto& s : all) {
        cout << s << endl;
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
