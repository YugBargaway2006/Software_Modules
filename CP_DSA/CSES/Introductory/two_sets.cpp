#include <bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define int long long 
#define f(i,k,n) for(int i = k; i < n; i++)

void printArray(const vector<int>& a);
 
void solve() {
    int n; cin >> n;
    if(n%4 == 1 || n%4==2) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    vector<long long> a, b;
    if(n%4==0) {
        int i = 1;
        while(i <= n) {
            a.push_back(i);
            a.push_back(i+3);
            b.push_back(i+1);
            b.push_back(i+2);
            i+=4;
        }
    } else {
        a.push_back(1);
        a.push_back(2);
        b.push_back(3);
        int i = 4;
        while(i <= n) {
            a.push_back(i);
            a.push_back(i+3);
            b.push_back(i+1);
            b.push_back(i+2);
            i+=4;
        }
    }
    
    cout << a.size() << endl;
    printArray(a);
    cout << b.size() << endl;
    printArray(b);
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
        cout << i << " ";
    }
    cout << endl;
}
