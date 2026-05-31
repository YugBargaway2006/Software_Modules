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
 
 
bool safe(vector<vi>& a, int i, int j) {
    for(int k = 0; k < i; k++) {
        if(a[k][j] == 2) return false;
    }
 
    for(int k = 1; k < 8; k++) {
        if(i-k >= 0 && j+k < 8 && a[i-k][j+k] == 2) return false;
        if(i-k >= 0 && j-k >= 0 && a[i-k][j-k] == 2) return false;
    }
 
    return true;
}
 
int count(vector<vi>& a, int i) {
    if(i == 8) {
        return 1;
    }
    // if(j == 8) {
    //     return count(a, i+1, 0);
    // }
 
    int total = 0;
    f(j,0,8) {
        if(a[i][j] == 1) continue;
        if(safe(a, i, j)) {
            cerr << "Good " << i << " " << j << endl;
            a[i][j] = 2;
            total += count(a, i+1);
            a[i][j] = 0;
        }
    }
    cerr << total << endl;
    return total;
}
 
 
void solve() {
    vector<vi> a(8, vi(8));
    f(i,0,8) {
        f(j,0,8) {
            char x; cin >> x;
            // cerr << 0*(x=='.') + 1*(x=='*') << "";
            a[i][j] = (0*(x=='.') + 1*(x=='*'));
        }
    }
    // f(i,0,8) {
    //     printArray(a[i]);
    // }
 
    cout << count(a, 0) << endl;
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
 
void printArray(const vector<int>& a) {
    for(auto i : a) {
        cerr << i << " ";
    }
    cerr << endl;
}
 