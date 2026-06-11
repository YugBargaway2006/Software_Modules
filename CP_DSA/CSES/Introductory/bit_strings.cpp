#include <bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define int long long 
#define INT_MAX LLONG_MAX
#define vi vector<int>
#define pi pair<int, int>
#define f(i,k,n) for(int i = k; i < n; i++)
#define mi map<int>
#define si set<int>
#define debug(i) cout << i << endl
 
int gcd(int a, int b);
void printArray(const vi& a);
int binexp(int base, int power, int mod);
int modInverse(int a, int mod);
int power(int base, int p, int mod);
 

void solve() {
    int n; cin >> n;
    int mod = 1e9 + 7;
    cout << power((long long)2, n, mod) << endl;
 
 
 
}
 
 
signed main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    // int t; cin >> t;
    int t = 1;
    while(t--) {
        // cout << "solve called" << endl;
        solve();
    }
}

 
void printArray(const vector<int>& a) {
    for(auto i : a) {
        cout << i << " ";
    }
    cout << endl;
}
 
int power(int base, int p, int mod) {
    if(p == 1) {
        return base % mod;
    }
    if(p <= 0) {
        return 1 % mod;
    }
 
    if(p % 2 == 0) {
        int ans = power(base, p/2, mod) % mod;
        return ans * ans % mod;
    } else {
        int ans = power(base, (p-1)/2, mod) % mod;
        return ans * ans * base % mod;
    }
}
 
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
 
int binexp(int base, int power, int mod) {
    int result = 1;
    while(power > 0) {
        if(power & 1) {
            result = (result * 1LL * base) % mod;
        }
        base = (base * 1LL * base) % mod;
        power >>= 1;
    }
    return result;
}
 
int modInverse(int a, int mod) {
    return binexp(a, mod-2, mod);
}
